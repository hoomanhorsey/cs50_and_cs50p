
import json
import requests
import sys

# API
# https://help.opendatasoft.com/apis/ods-explore-v2/#section/Opendatasoft-Query-Language-(ODSQL)/Select-clause
# longtitude latitude coords api
# https://learn.microsoft.com/en-us/bingmaps/rest-services/locations/find-a-location-by-point

#if len(sys.argv) != 2:
#    sys.exit()


#respond = requests.get("https://public.opendatasoft.com/api/v2/geonames-all-cities-with-a-population-1000@public")

cityname = input("{Insert instructions}What is the name of the city? ")

respon = requests.get("https://documentation-resources.opendatasoft.com/api/v2/catalog/datasets/geonames-all-cities-with-a-population-1000/records?&sort=population desc&limit=100&select = ascii_name, cou_name_en, population, coordinates &facet=cou_name_en&facet=timezone&timezone=Australia%2FSydney&where = ascii_name ='"+cityname+"'")

print("")
o = respon.json()
print("We've found the following cities that match the name you've entered: ")
print("")

cities = []
n = 1
for result in o["records"]:
    #print(n, result["record"]["fields"]["ascii_name"], result["record"]["fields"]["cou_name_en"], result["record"]["fields"]["population"], result["record"]["fields"]["coordinates"])
    cities.append( {"ref": n, "name": result["record"]["fields"]["ascii_name"], "state/province": None, "country": result["record"]["fields"]["cou_name_en"], "population" : result["record"]["fields"]["population"], "coordinates" :  result["record"]["fields"]["coordinates"]})
    n += 1
#print(cities)

for city in cities:
    #print(index)
    # insert state/province by geo coords
    for i in city:

        coords = {}
        coords = city["coordinates"]
        #print(coords)

        lon = coords["lon"]
        lat = coords["lat"]
        #print(lon)
        #print(lat)

    locale = requests.get("https://geocode.maps.co/reverse?lat="+str(lat)+"&lon="+str(lon))
    l = locale.json()
    city["state/province"] = l["address"]["state"]

    for z in city:
        print(z, ": ",  city[z])


    #print(l["address"]["state"])

    #print(json.dumps(locale.json(), indent=2))
    print("")


#print(city["name"], city["state/province"])

print("")
    #for i in index:
    #    print(i[i]["name"])
     #for z in coords:
    #    print("z,", z)

#print(cities)

confirm = int(input("Is that the city that you were thinking of?  Please confirm the name of the city by entering the reference number: "))
print(confirm)

"""
    cities.append( {n:[{"index": n}, {"name": result["record"]["fields"]["ascii_name"]}, {"state/province": None}, {"country": result["record"]["fields"]["cou_name_en"]}, {"population" : result["record"]["fields"]["population"]}, {"coordinates" :  result["record"]["fields"]["coordinates"]}]})
"""

#print(json.dumps(respon.json(), indent=2))

#print(cities)
for citlee in cities:
    #print(citlee)
    for n in citlee:
        if citlee["ref"] == confirm:
            keypop = (citlee["population"])
        else:
            continue
print(type(keypop), keypop)

lowerpop = str(int(keypop*.95))
upperpop = str(int(keypop*1.05))

print(keypop, lowerpop, upperpop)
#Now find cities with a similar population size!!!!




#need to exclude your key city from the search!
#Exclude by referencing 'keypop'!
finalcities = requests.get("https://documentation-resources.opendatasoft.com/api/v2/catalog/datasets/geonames-all-cities-with-a-population-1000/records?&sort=population desc&limit=30&select = ascii_name, cou_name_en, population, coordinates &facet=cou_name_en&facet=timezone&timezone=Australia%2FSydney&where=population>"+lowerpop+"&where=population<"+upperpop)


print(finalcities)

final = finalcities.json()
print(json.dumps(finalcities.json(), indent=2))

popcities = []
no = 1
for presult in final["records"]:
    #print(n, result["record"]["fields"]["ascii_name"], result["record"]["fields"]["cou_name_en"], result["record"]["fields"]["population"], result["record"]["fields"]["coordinates"])
    popcities.append( {"ref": no, "name": presult["record"]["fields"]["ascii_name"], "state/province": None, "country": presult["record"]["fields"]["cou_name_en"], "population" : presult["record"]["fields"]["population"], "coordinates" :  presult["record"]["fields"]["coordinates"]})
    no += 1

    for cit in popcities:
        #print(index)
        # insert state/province by geo coords
        for j in cit:

            pcoords = {}
            pcoords = cit["coordinates"]
            #print(coords)

            plon = pcoords["lon"]
            plat = pcoords["lat"]
            #print(lon)
            #print(lat)

            plocale = requests.get("https://geocode.maps.co/reverse?lat="+str(plat)+"&lon="+str(plon))
            pl = plocale.json()
            cit["state/province"] = pl["address"]["state"]




    for za in cit:
        print(za, ": ",  cit[za])



#print(popcities)

"""
- get the name of the city from user - DONE
- get the pop of the city from api DONE
- confirm idenity of city, by country and co-ordinates.....DONE
- calculate the pop of the city, and the range (+ 1%, -1% )
    - possibly do all in one call
- return a list of cities and their populations that are simlar
- app map co-ordinates?.
"""


"""
### request that asks for 10 items, listed by population size descending,
respond = requests.get("https://documentation-resources.opendatasoft.com/api/v2/catalog/datasets/geonames-all-cities-with-a-population-1000/records?&sort=population desc&limit=10&facet=cou_name_en&facet=timezone&timezone=Australia%2FSydney&select=population, ascii_name&where = population > 500000&where = population < 600000")

print(json.dumps(respond.json(), indent=2))


o = respond.json()
for result in o["records"]:
    print(result["record"]["fields"]["ascii_name"])
"""

#print("The name of the city is: " +cityname)
#print(json.dumps(respon.json(), indent=2))

#print(json.dumps(respon.json(), indent=2))

#print(o)#for result in o["records"]:
#    print(result["fields"]["ascii_name"])
    #for p in result["fields"]:
    #    print)
    #print("")
 #       print(result["fields"])
        #for q in p:#["name"]:
        #    print(q)
#        print(p, type(p))
 #       print(p[0])



