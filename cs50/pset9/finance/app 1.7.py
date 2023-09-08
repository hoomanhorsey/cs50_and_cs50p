import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd


# Version 1.2
# Register is complete! Next task is Quote
# Version 1.3
# Quote is complete! Next task is Buy
# Version 1.4
    # - extracting cash from the db delivers a list, and then extracting the value from the key/value pair creates another list, but then extracting the value from that list does eventually deliver the value.  Why does it need to be done twice?
    # -there's a log in error if your registration is incorrect it may log you in by default as the first user.  And then you can potentially transact as them.

##NOTES, CONSIDER STORING DOLLAR VALUES AS 'DECIMAL' IN THE DATABSSE, IN CASE THE ENDLESS decimals gets unwieldy. - https://www.sqlshack.com/understanding-sql-decimal-data-type/, or 'REAL' number, based on SQLite affinities

## NEXT TASK IS THe BUY FUNCTION, TESTING FOR POSITIVE INTEGERS.

#Version 1.5
#Index function is complate, although nothing is formatted. Now onto Sell function

#Version 1.6
#Finished Sell function.  Previously had 2 ledger tables, but reduced it to one table to account for both buy and sell transactions.
#Version 1.7 Finished, except for the check 50 test. Need to consolidate the buy + sell functions to render index.html. Currently they do their own screens, which the check50 does not want. So some rejigging is required.


# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # NOTE - Extracts from joined 'user' and 'ledger' tables
    index = db.execute("SELECT stock, symbol, SUM(sharesbought) AS sum_sharesbought, SUM(sharessold) AS sum_sharessold, cash FROM ledger INNER JOIN users ON users.id = ledger.user_id WHERE user_id = ? GROUP BY stock", session["user_id"])

    # inserts current prices into 'index' list, by iterating through each stock
    for z in index:  #iterates through numbered rows of index
        for y in z.keys(): # for each row, iterates through the key values
            if y == 'symbol': #if the key value is 'symbol', then we need to access the value.
                value = lookup(z["symbol"])  #send symbol to lookup api
                z["price"] = value["price"] # extract price from value, and insert it into the 'z dict' as a new key: value pair.
                break #once found, proceed to next stock.

    # Deletes stocks with zero balance from 'index' list
    for p in index:
        print(p)
        for q in p.keys():
            if q == 'sum_sharesbought':
                sb = p['sum_sharesbought']
            if q == 'sum_sharessold':
                ss = p['sum_sharessold']
                if ((sb - ss) == 0):
                    index.remove(p)

    # Extract cash from db. For some reason extracting cash from db in jinja transforms it into a string, and can't use usd.
    if len(index) == 0:
        cash = 0

    else:
        cash = index[0]['cash']

    # Calculate Value of Shares + Cash = Grand Total
    subtotal = 0
    for j in index:
        total = (j['price'] * (j['sum_sharesbought'] - j['sum_sharessold']))
        subtotal += total

    grandtotal = cash + subtotal

    #renders index template
    return render_template("index.html", cash=cash, grandtotal=grandtotal, index=index)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Get symbol and shares from form
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        stock = lookup(symbol) # uses lookup to query stock API, results in a dict which is inserted into 'stock' variable

        # Check stock quote was submitted,  #Must include shares number,
        if not symbol:
            return apology("Please provide a stock symbol.", 400)

        # Check stock symbol exists,
        elif stock is None:
            return apology("Sorry. This stock symbol doesn't exist. Please enter another.", 400)

        # Checks that number of shares entered are digits only, and not a string.
        elif (shares.isdigit()) != True:
            return apology("Please enter a number for the shares you wish to purchase.", 400)
            #THis doesn't work as the input is 'text' so it comes as a string.

        # Ensure number of shares is entered, is an integer, and is a positive numer
        elif (not shares ) or (float(shares)- int(float(shares)) > 0) or (float(shares) <= 0):
            return apology("Sorry. Number of shares you wish to purchase must be a positive number. Or an integer.", 400)
        shares = int(shares) #Temp cast 'shares' as float for integer test, and now casting back to int.

        # Checks completed, continue with calculations

        # Extracts value of'price' from the dict named 'stock'.  Note, price may go up to  4 decimal places
        stockprice = stock["price"]

        # Query SQL user database to extract 'cash' item
        cash_db = db.execute("SELECT cash FROM users WHERE ID = ?", session["user_id"]) # extracts cash amount from the user db, in a key:value pair stored as a list of one dict.
        cash = cash_db[0]['cash'] #cash variable stores the results of the query in a list of one dict.
        #To extract the value of the key, reference the first and only entry of the 'cash_db[0]', then by reference the 'key' ['cash'] it gives us the value.

        # Calculate consideration
        consideration = (shares * stockprice) #calculating consideration

        # Check that buyer can afford purchase
        if consideration > cash:
            return apology("Dude! You don't have enough cash to buy these shares", 403)

        # Update ledger table to include purchase details:   'Date' is timestamped on entry.
        # Note: 'sharessold' is included with a value of '0' as the table does not allow a Null entry. Also, the '0' is used for later calculations.
        db.execute("INSERT INTO ledger (user_id, stock, symbol, sharesbought, sharessold, shareprice, consideration) VALUES(?, ?, ?, ?, ?, ?, ?)", session["user_id"], stock["name"], symbol, shares, 0, stockprice, consideration,)

        #  Update user table to update 'cash'
        cash = (cash - consideration)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

        # ####NOTE NOTE### Return 'bought' template, which is temporary. Probably need to go to 'index' template.
        return render_template("bought.html", cash=cash, consideration=consideration, shares=shares, stock=stock, stockprice=stockprice)

    ## User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Extracts from joined 'user' and 'ledger' tables
    history = db.execute("SELECT stock, symbol, sharesbought, sharessold, shareprice, cash, date FROM ledger INNER JOIN users ON users.id = ledger.user_id WHERE user_id = ? GROUP BY date", session["user_id"])
    print(history)
    #renders index template
    return render_template("history.html", history=history)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("Please provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("Please provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Get symbol, then call 'lookup' function  to extract info from API and store in 'quote'
        symbol = request.form.get("symbol")
        quote = lookup(symbol)

        # Check symbol was submitted, # Check symbol is valid
        if not symbol:
            return apology("Please provide a stock symbol", 400)

        if quote is None:
            return apology("Oopsie. That stock doesn't exist", 400)

        return render_template("quoted.html", quote=quote)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

     # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        username = request.form.get("username")
        password = request.form.get("password")
        passwordconfirm = request.form.get("confirmation")

        # Ensure username was submitted
        if not username:
            return apology("Please provide username", 400)

        # Ensure password was submitted
        elif not password:
            return apology("Please provide password", 400)

       # Password confirmation must match password
        elif password != passwordconfirm:
            return apology ("Passwords do not match. Please try again.", 400)

        # Check to see if username already exists
        existingusername = db.execute("SELECT * FROM users")
        for x in existingusername:
            if x["username"] == username:
                session.clear()
                return apology("Username is already being used. Please choose another.", 400)

        # Insert user and password (hashed) into databse
        hash = generate_password_hash(password, method='pbkdf2:sha256', salt_length=8)
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

                #inserts user's id from database into session so that the user is logged in.
                # NOTE:this code seems to create problems if the login is unsucessful for some reason as it still logs the user in.
                # session["user_id"] = db.execute("SELECT id FROM users WHERE username = username")

        return render_template("login.html")

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    #Selects stocks from ledger, and omits those with '0' balance.
    # NOTE - Extracts from joined 'user' and 'ledger' tables
    index = db.execute("SELECT stock, symbol, SUM(sharesbought) AS sum_sharesbought, SUM(sharessold) AS sum_sharessold, cash FROM ledger INNER JOIN users ON users.id = ledger.user_id WHERE user_id = ? GROUP BY stock", session["user_id"])

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Get symbol and shares from form
        symbol = request.form.get("symbol")
        print(symbol)
        shares = request.form.get("shares")
        stock = lookup(symbol) # uses lookup to query stock API, results in a dict which is inserted into 'stock' variable
        print(stock)

        # Check stock quote was submitted,  #Must include shares number,
        if not symbol:
            return apology("Please provide a stock symbol.", 400)

        # Check stock symbol exists,
        elif stock is symbol:
            return apology("Sorry. This stock symbol doesn't exist. Please enter another.", 400)

        # Ensure number of shares is entered, is an integer, and is a positive numer
        elif (not shares ) or (float(shares)- int(float(shares)) > 0) or (float(shares) <= 0):
            return apology("Sorry. Number of shares you wish to sell must be a positive integer.", 400)
        shares = int(shares) #Temp cast 'shares' as float for integer test, and now casting back to int.

        # Check to see if user has the shares to sell
        ledgercheck = db.execute("SELECT symbol, SUM(sharesbought) AS sum_sharesbought, SUM(sharessold) AS sum_sharessold FROM users JOIN ledger ON users.id = ledger.user_id WHERE ledger.user_id = ? AND ledger.symbol = ? GROUP BY ledger.stock", session["user_id"], symbol)

        print(ledgercheck)

        #check to see if stock exists in ledger **NOTE THIS IS A VERY CONVOLUTED CHECK. THERE MUST BE A SIMPLER WAY
        i = 0
        for x in ledgercheck:
            for y in x.values():
                if  y == (stock['symbol']).lower():  # use the lowercase function as it shifts it to upper case for some reason.
                    i = i + 1
        if (i < 1):
            print(i)
            return apology("Sorry. You don't own these shares", 400)

        #check to see if you have enough shares to sell
        elif shares > (ledgercheck[0]['sum_sharesbought'] - ledgercheck[0]['sum_sharessold']):
            return apology("Sorry. You don't have enough shares to sell this amount.", 403)

        # Query SQL user database to extract 'cash' item
        cash_db = db.execute("SELECT cash FROM users WHERE ID = ?", session["user_id"]) # extracts cash amount from the user db, in a key:value pair stored as a list of one dict.
        cash = cash_db[0]['cash'] #cash variable stores the results of the query in a list of one dict.
        #To extract the value of the key, reference the first and only entry of the 'cash_db[0]', then by reference the 'key' ['cash'] it gives us the value.


        # Calculate proceeds
        stockprice= stock["price"]
        consideration = (shares * stockprice)
        print(stockprice)
        cash = round((cash + consideration), 2)

        print(cash)

        #  Update ledger_sell table to include sale of shares.

        db.execute("INSERT INTO ledger (user_id, stock, symbol, sharesbought, sharessold, shareprice, consideration) VALUES(?, ?, ?, ?, ?, ?, ?)", session["user_id"], stock["name"], symbol, 0, shares, stockprice, consideration)

        #  Update user table to update 'cash'

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])




       # inserts current prices into 'index' list, by iterating through each stock
        for z in index:  #iterates through numbered rows of index
            for y in z.keys(): # for each row, iterates through the key values
                if y == 'symbol': #if the key value is 'symbol', then we need to access the value.
                    value = lookup(z["symbol"])  #send symbol to lookup api
                    z["price"] = value["price"] # extract price from value, and insert it into the 'z dict' as a new key: value pair.
                    break #once found, proceed to next stock.
        # Deletes stocks with zero balance from 'index' list
        for p in index:
            print(p)
            for q in p.keys():
                if q == 'sum_sharesbought':
                    sb = p['sum_sharesbought']
                if q == 'sum_sharessold':
                    ss = p['sum_sharessold']
                    if ((sb - ss) == 0):
                        index.remove(p)


        # Calculate Value of Shares + Cash = Grand Total
        subtotal = 0
        for j in index:
            total = (j['price'] * (j['sum_sharesbought'] - j['sum_sharessold']))
            subtotal += total

        grandtotal = cash + subtotal


        return render_template("index.html", cash=cash, grandtotal=grandtotal, index=index)
        # return render_template("sold.html", cash=cash, consideration=consideration, shares=shares, stock=stock, stockprice=stockprice, index=index)

   ## User reached route via GET (as by clicking a link or via redirect)

    else:

        for p in index:
            print(p)
            for q in p.keys():
                if q == 'sum_sharesbought':
                    sb = p['sum_sharesbought']
                    print(sb)
                if q == 'sum_sharessold':
                    ss = p['sum_sharessold']
                    print(ss)
                    if ((sb - ss) == 0):
                        index.remove(p)
                        print('to be deleted')
                        print(index)

        return render_template("sell.html", index=index)



