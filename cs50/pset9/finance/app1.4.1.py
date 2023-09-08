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
# Versiion 1.4.1
    #Wrangling with Index. Trying to access prices of stock, and updating current prices using lookup.

##NOTES, CONSIDER STORING DOLLAR VALUES AS 'DECIMAL' IN THE DATABSSE, IN CASE THE ENDLESS decimals gets unwieldy. - https://www.sqlshack.com/understanding-sql-decimal-data-type/, or 'REAL' number, based on SQLite affinities

## NEXT TASK IS THe BUY FUNCTION, TESTING FOR POSITIVE INTEGERS.




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


#Complete the implementation of index in such a way that it displays an HTML table summarizing, for the user currently logged in, which stocks the user owns, the numbers of shares owned, the current price of each stock, and the total value of each holding (i.e., shares times price). Also display the user’s current cash balance along with a grand total (i.e., stocks’ total value plus cash).

#Odds are you’ll want to execute multiple SELECTs. Depending on how you implement your table(s), you might find GROUP BY HAVING SUM and/or WHERE of interest.
#Odds are you’ll want to call lookup for each stock.

    ## Selection order.
        # SELECT Symbol WHERE ID = ID, # Will create an list.
            #FOR LOOP
            #Iterate for each Symbol, SELECT sharesbought AND [dynamic price], will create a list comprised of Shares bought and price.
                #mmultiply the sharesbought * price to find consideration.

                #new entries. 1) Total units held.  2) Total consideration paid

        # SELECT Cash WHERE id = id,

        # Grand Total is Cash + TOtal consideration.

    Stocks_Owned_db = db.execute("SELECT stock, symbol, SUM(sharesbought) AS sum_sharesbought, cash FROM ledger_buy INNER JOIN users ON users.id = ledger_buy.user_id WHERE user_id = ? GROUP BY stock", session["user_id"])

    #Stocks_Owned_db = db.execute("SELECT stock, symbol, SUM(sharesbought) AS sum_sharesbought FROM ledger_buy WHERE user_id = ? GROUP BY stock", session["user_id"])
    #Current_Prices = 0
    #for i in Current_Prices:
    #    Current_Prices = lookup(request.form.get(Stocks_Owned_db[i]['symbol']))  ## Trying to access the value of 'symbol' that is include in the output of 'Stocks_Owned_db' created from lookup
    #   Current_Prices = lookup(request.form.get(Stocks_Owned_db[0]['symbol']))  ## Trying to access the value of 'symbol' that is include in the output of 'Stocks_Owned_db' created from lookup

    #Current_Prices = 0
    #for p in Stocks_Owned:
    #    Current_Prices[p] = lookup(request.form.get(Stocks_Owned[0]['symbol']))


    #Symbol = db.execute("SELECT stock, SUM(sharesbought) AS sum_sharesbought FROM ledger_buy WHERE user_id = ? GROUP BY stock", session["user_id"])
    #symbol = db.execute("SELECT symbol FROM ledger_buy")
    #stock = lookup(request.form.get(symbol))




    ##Current_Price = 4 #(stock["price"] * Stocks_Owned["sum_sharesbought"])
    Current_Prices =0
    Total_Value=0
    Cash_Balance=0
    Grand_Total=0


    return render_template("index.html", Stocks_Owned=Stocks_Owned_db, Current_Prices=Current_Prices, Total_Value=Total_Value, Cash_Balance=Cash_Balance, Grand_Total=Grand_Total) #stock=stock)






@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

    # Ensure a stock quote was submitted
        symbol = request.form.get("symbol")
        if (not symbol):
        #if (not request.form.get("symbol")):
            return apology("Must provide stock symbol", 403)

    # Ensure stock symbol exists
        elif (lookup(request.form.get("symbol")) is None):
            return apology("No such stock symbol", 403)

    # Must include shares number
        elif (not request.form.get("shares")):
            return apology("Must include number of shares", 403)

    # Ensure number of stocks entered is a positive integer
        shares = request.form.get("shares")
        if (float(shares)- int(float(shares)) > 0) or (float(shares) <= 0):
            return apology("Number of shares must be a positive number. Or an integer.", 403)
        sharesbought = int(shares) #Temp cast 'shares' as float for integer test, and now casting back to int.

    # Proceed with calculations
        stock = lookup(request.form.get("symbol")) # uses lookup to query stock API, results in a dict which is inserted into 'stock' variable
        stockprice = stock["price"]  #extracts value of 'price' from the dict named 'stock'.  Note, price may go up to  4 decimal places

    # Query SQL user database to extract 'cash' item

        cash_db = db.execute("SELECT cash FROM users WHERE ID = ?", session["user_id"]) # extracts cash amount from the user db, in a key:value pair stored as a list of one dict.
        cash = cash_db[0]['cash'] # as it's a list of 1 dict, need to reference the first entry of dict [0], then reference the 'key' ['cash'], which then gives us the 'value' of that 'key'.

    #Buying calculations
        #buyableunits = int(cash / stockprice) # amount of units that can be bought, rounded down to an int. - **NOTE**probably don't need this.
        consideration = (sharesbought * stockprice) #calculating consideration
        ##consideration = float(consideration) **NOTE** probably don't need this.

        #Render an apology, without completing a purchase, if the user cannot afford the number of shares at the current price.
        if consideration > cash: #determines whether user has enough cash to buy
            return apology("Dude! You don't have enough cash to buy these shares", 403)

        updatedcash = (cash - consideration)

        ## TODO - Update user table to subtract spent cash
        ##        Update ledgerpurchase table to include details of purchase


            #Add one or more new tables to finance.db via which to keep track of the purchase. Store enough information so that you know who bought what at what price and when.
                #Use appropriate SQLite types.
                #Define UNIQUE indexes on any fields that should be unique.
                #Define (non-UNIQUE) indexes on any fields via which you will search (as via SELECT with WHERE).

                ## NOW NEED TO Create a new database with the follow items - id of purchaser, number of units bought, price when bought, date

        # Inserts purchase details into 'ledger_buy' table.  'Date' is timestamped on entry.
        db.execute("INSERT INTO ledger_buy (user_id, stock, symbol, sharesbought, shareprice, consideration) VALUES(?, ?, ?, ?, ?, ?)", session["user_id"], stock["name"], symbol, sharesbought, stockprice, consideration,)

        # Then insert 'updated cash' into users, for cash

        db.execute("UPDATE users SET cash = ? WHERE id = ?", updatedcash, session["user_id"])



        return render_template("bought.html", cash=cash, consideration=consideration, shares=shares, stock=stock, stockprice=stockprice, updatedcash=updatedcash)

        #return render_template("bought.html", cash=cash, consideration=consideration, shares=shares, stock=stock, stockprice=stockprice, updatedcash=updatedcash)

#        return render_template("bought.html", bought=bought, buyableunits=buyableunits, shares=shares, purchaseprice=purchaseprice, boughtunits=boughtunits)

        # db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)




    ## User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

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

        # Ensure quote was submitted
        if not request.form.get("symbol"):
            return apology("Please provide quote", 403)
        # Ensure quote exists.
        elif (lookup(request.form.get("symbol")) is None):
            return apology("Oopsie. That stock doesn't exist", 403)

        # Use lookup function to extract quote from API
        quote = lookup(request.form.get("symbol"))
        return render_template("quoted.html", quote=quote)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

     # Forget any user_id
    session.clear()
    username = 0

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("Please provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("Please provide password", 403)

       # Password confirmation must match password
        elif (request.form.get("password")) != (request.form.get("confirmation")):
            return apology ("Passwords do not match. Please try again.", 403)

        # Check to see if username already exists
        newusername = request.form.get("username")
        existingusername = db.execute("SELECT * FROM users")
        for x in existingusername:
            if x["username"] == newusername:
                session.clear()
                return apology("Username is already being used. Please choose another.", 403)

        # Insert user and password (hashed) into databse
        username = request.form.get("username")
        hash = generate_password_hash(request.form.get("password"), method='pbkdf2:sha256', salt_length=8)
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

        #inserts user's id from database into session so that the user is logged in.
        # session["user_id"] = db.execute("SELECT id FROM users WHERE username = username")

        return render_template("login.html")

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")



