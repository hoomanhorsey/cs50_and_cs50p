
import json
import requests
import sys


def main():

    print("\nWelcome to StadtDoppelganger!\n\nThe purpose of this program is to discover your city's StadtDoppelganger.  That is, a selection of cities that have similar sized populations as the one you nominate.")
    print("")
    print("What is the name of the city that you wish to find the StadtDoppelganger for? \n\nNote: please use the English name of the city, and do be careful of the correct spelling.  Certain cities have variations on their spelling so if you don't find your city, please try again with a different spelling.\n")

    end = "Y"
    while end.upper() == "Y":

        # Functions keep on looping until a final city is chosen and included as a list....
        chosencityaslist = None
        while chosencityaslist == None:

            # get city name - check if valid via geo API
            citylist = None
            while citylist == None:

                # Get's cityname from user

                cityname = input("City name: ")
                citylist = getcitylist(cityname)
                if citylist != None:
                    break
                else:
                    print("I'm sorry that city isn't in our database. Please check spelling and try again.")

            stateprovince = "placeholder"
            # insert state/province into list of cities using lat/long coords
            citylist = getstate(citylist)

            # Print list of cities with name:
            print("\nWe've found the following cities that match the name you've entered: ")
            print("")
            for city in citylist:
                for z in city:
                    if z == "population":
                        print(z, ": ",  "{:,}".format(city[z]))
                    else:
                        print(z, ": ", city[z])
                print("")

            # Allows user to select specific city from a list of all cities with the same cityname

            chosencityaslist = selectcity(citylist)

        # Once a city is chosen, extract key data from 'chosencityaslist'

        for city in chosencityaslist:
            match city:
                case "population":
                    keypop = chosencityaslist[city]
                case "state/province":
                    stateprovince = chosencityaslist[city]
                case "country":
                    country = chosencityaslist[city]
                case _:
                    continue


        # function creates a list of all cities with similar population

        citiesbypop = poplist(keypop)

        # prints list of cities with similar population
        if stateprovince == "Not applicable":
            print(f"\nThe population of {cityname}, {country}, is {'{:,}'.format(keypop)}. \n\nHere are some cities with similar populations.\n")
        else:
            print(f"\nThe population of {cityname}, {stateprovince} is {'{:,}'.format(keypop)}. \n\nHere are some cities with similar populations.\n")

        # calls get getstate() to insert state/provinces into final list.maybe
        citiesbypop = getstate(citiesbypop)


        for city in citiesbypop:
            for za in city:
                if za == "population":
                    print(za, ": ",  "{:,}".format(city[za]))
                else:
                    print(za, ": ",  city[za])
            print("")

        answer = "N"
        while answer == "N":
            ## insert question asking if they want a print out file, and name of file......
            answer = input("Would you like to create a text file of your results? If so, please provide a name for the file, or type 'N' if you don't wish to save a file.\nName of File, or 'N': ")

            if answer.upper() == "N":
                break
            else:
                with open(answer+".txt", "a") as file:

                    if stateprovince == "Not applicable":
                        file.write("These are the StadtDoppelgangers of the city of "+cityname+", "+country+", population ("+str("{:,}".format(keypop)+").\n\n"))
                    else:
                        file.write("These are the StadtDoppelgangers of the city of "+cityname+", "+stateprovince+", population ("+str("{:,}".format(keypop)+").\n\n"))

                    for c in citiesbypop:
                        for z in c:
                            if z == "population":
                                file.write(z)
                                file.write(": ")
                                file.write(str("{:,}".format(c[z])) + "\n")
                            else:
                                file.write(z)
                                file.write(": ")
                                file.write(str(c[z]) + "\n")
                        file.write("\n")
                    file.close()
                print(f"\nGreat! There'll be a file named \"{answer}.txt\" saved into your directory for you to look at.")

        end = input("\nWould you like to try another city?  Enter 'Y' if you would, 'N' if you wish to quit: ")

        if end.upper() == "N":
            sys.exit("\nThank you for StadtDoppelganging!")



# Functions

# get list of cities, insrting state/province from coords as well.
def getcitylist(cityname):

    response = requests.get("https://documentation-resources.opendatasoft.com/api/v2/catalog/datasets/geonames-all-cities-with-a-population-1000/records?&sort=population desc&limit=100&select = ascii_name, cou_name_en, population, coordinates &facet=cou_name_en&facet=timezone&timezone=Australia%2FSydney&where = ascii_name ='"+cityname+"'")

    o = response.json()

    # inserting city name search results into list 'cities'
    citylist = []
    n = 1
    for result in o["records"]:
        citylist.append({"ref": n, "name": result["record"]["fields"]["ascii_name"], "state/province": None, "country": result["record"]["fields"]["cou_name_en"], "population" : result["record"]["fields"]["population"], "coordinates" :  result["record"]["fields"]["coordinates"]})
        n += 1

    #returns 'None' if the search for a city results in no response.
    if len(citylist) < 1:
        return None
    return citylist


# inserts state/provice by lon/lat coords
def getstate(citylist):

    for city in citylist:
        coords = {}
        coords = city["coordinates"]
        lon = coords["lon"]
        lat = coords["lat"]

        locale = requests.get("https://geocode.maps.co/reverse?lat="+str(lat)+"&lon="+str(lon))
        l = locale.json()

        for x in l["address"]:
            if x == "state":
                city["state/province"] = l["address"]["state"]
                break
            else:
                city["state/province"] = "Not applicable"

    return citylist

# selects city by choosing ref number
def selectcity(citylist):

    refnumlist = []
    for x in citylist:
        refnumlist.append(x["ref"])

    print("Is your city included in this list?  ")
    refnum = 0
    while refnum not in refnumlist:

        refnum = input("\nPlease confirm the name of the city by entering the reference number. Enter 'N' if your city is not included, and re-enter your city name: ")

        if refnum.upper() == 'N':
            return None

        try:
            if int(refnum) in refnumlist:
                chosencityaslist = []
                for city in citylist:
                    if city["ref"] == int(refnum):
                        chosencityaslist = city
                        return chosencityaslist
        except:  #takes care of errors when user doesn't enter an int or 'N'
            TypeError


# selects cities with simliar populations to the one selected
def poplist(keypop):

    lowerpop = str(int(keypop*.95))
    upperpop = str(int(keypop*1.05))

    finalcities = requests.get("https://documentation-resources.opendatasoft.com/api/v2/catalog/datasets/geonames-all-cities-with-a-population-1000/records?&sort=population desc&limit=10&select = ascii_name, cou_name_en, population, coordinates &facet=cou_name_en&facet=timezone&timezone=Australia%2FSydney&where=population>"+lowerpop+"&where=population<"+upperpop)

    final = finalcities.json()

    citiesbypop = []
    no = 1
    for result in final["records"]:

        # excludes the chosen city from the final list
        if result["record"]["fields"]["population"] == keypop:
            continue
        else:
            citiesbypop.append( {"ref": no, "name": result["record"]["fields"]["ascii_name"], "state/province": None, "country": result["record"]["fields"]["cou_name_en"], "population" : result["record"]["fields"]["population"], "coordinates" :  result["record"]["fields"]["coordinates"]})
            no += 1
    return citiesbypop

if __name__ == "__main__":
    main()

