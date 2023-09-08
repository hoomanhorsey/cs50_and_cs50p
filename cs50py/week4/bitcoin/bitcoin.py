import sys
import requests
import json

try:
    amount = float(sys.argv[1])

except ValueError:
    print("Command-line argument is not a number")
    sys.exit
except IndexError:
    print("Missing command-line argument")
    sys.exit


try:
    b = requests.get('https://api.coindesk.com/v1/bpi/currentprice.json')
except requests.RequestException:
    print("Request error?")

#print out of request, formatted
#print(json.dumps(b.json(), indent=2))

b = b.json()

amount = (b['bpi']['USD']['rate_float']) * amount.  #access nesting dict value

print(f"${amount:,.4f}")
