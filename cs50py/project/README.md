# StadtDoppelganger

## Video Demo:  https://youtu.be/TnHFaXWmc9g

## Description:
StadtDoppelganger is a simple CLI python program that allows you to enter the name of a city, and then creates a list of cities from around the world that have a similar population.  That is, it finds the StadtDoppelgangers for your nominated city.

## Observations and Challenges


I iniitally thought the project would be quite straightforward. Perhaps too straightforward as a final project. And while it is from a programming perspective, I soon realised that there was a great deal of complexity where the code sought to interact with the real world.  Both in terms of accessing APIs as well as reflecting on the many variations of city names that exist in the world (different languages, different spellings).  ULtimately the project took me a lot longer to complete than I first anticipated, and it also utilised a lot less of the tools described in the course that I hoped I would use.

For example, I didn't use anything like a custom made class or object in the project.  Although obviously I use many of the built in classes used in python.  At the moment, I'm reassuring myself that being exposed to these concepts and understanding some of these concepts is the first step in learning, with the next step actually using these tools.  While I hoped to use these tools in my final project, I couldn't actually make a case for their inclusion. And that's partly because I didn't fully comprehend their features or how to implement them.  All in good time I think, if I continue to learn python/coding.

I hope that my project is sufficiently complex to complete the course. And if it isn't I guess I will go back and make a more complex project.  The coursework states that the project should take up more time than any of the problem sets included in the course work.  This doesn't really account for the fact that some people have difficulty learning these concepts or might be slower, and so their project may take much longer, but not end up being very complicated.  Or perhaps it does take that into account.  Either way, my project took me several (time interrupted) weeks, so it certainly took much longer than any of the problem sets!

### APIs

It was quite challenging finding a reputable free API that I could use to access information about cities.  There are many APIs that exist, some of which require keys and subscriptions to utilise, without necessarily providing references from which they gather their data.  Some APIs, like the Apple Maps API, require a paid developer account to access. While the fee is modest for a working developer it's a bit steep for a student.

The project uses the following free APIs

- one to gather city names. All cities with pop. above 1,000

   https://data.opendatasoft.com/explore/dataset/geonames-all-cities-with-a-population-1000%40public/information/?disjunctive.cou_name_en&sort=name

   Which uses it's own SQL like language

   https://help.opendatasoft.com/apis/ods-explore-v2/#section/Opendatasoft-Query-Language-(ODSQL)/Select-clause

- and the second to identify the state/province of each city using lon/lat co-ordinate (reverse geocode for maps)

    https://geocode.maps.co

It took a little while to wrangle the data out of the API. But once I understand how to change the parameters of each call to the API, and then allow those parameters to be changed programatically, I started to get the swing of it.


### City Names

I went into this project somewhat naively not appreciating how much complexity and edge cases there are with city names.

Spelling - I've used English as the default input language, but it's important to acknowledge that most cities in the world aren't natively spelt in English (duh) and if they do have an English name it isn't necessarily consistent. The API has a range of alternative names other than one key 'ascii_name'.   The program could potentially go through these programatically to tease out alternative spellings.  However, this would probably be quite clunky in CLI.  However, if the program was made via a web app the names could be downloaded into a list, and the program could iterate through these names with an auto-complete type feature to make it easier.

I considered converting input of city name to uppercase to make for betttr matching, but can't because the place names in the API are hard coded with uppercase and lower case characters.

### City v Regions

I was inspired to make a tool like this after learning that the population of Melbourne is similar to the entire population of Scotland.  Ideally I could make a tool that is able to compare cities with regions, like states, provinces or even entire countries.  But I'm not quite sure how to identify and wrangle the APIs to give me consistent data at this moment.

### Veracity of Data

Who provides the information for city populations? How often is it updated?  How is a city defined?  Each country, and even within countries, has and have different ways of demarcating territories or regions.  Population statistics differ wherever you look. Some cities are defined by the inner metropolitan administrative area whereas others included the greater metropolitan region.


Sydney is considered one city, but within Sydney various municipalities claim city status.  Whereas Vancouver is considered a city, but the region is comprised of one city called Vancouver, which is bordered by other cities like Richmond and Surrey, which are of a similar size but not necessarily the same population or density or infrastructure.

Then there are other outliers like Monaco and The Vatican, which are odd city states.

All this has made me appreciate that while one needs good clean and consistent data to programatically process and achieve the outcomes you want, the world itself is a lot messier and in many circumstances one needs to accept some compromise in how accurate that data is in reflecting all realities or considerations.  Otherwise no work will be done.

### No. of cities

At the moment, the list of StadtDoppelgangers is capped at 10.  It is possible to insert a feature for the user to nominate how many cities they want included in the list.

Also, the range of similarity between the user nominated cities and other StadtDoppelgangers is capped at 5% population difference.  When cities are of larger populations, this cap reduces the number of like cities as there are fewer other cities that fall in this range.  Consider including functionality that checks to see how many results there are, and if there are less than 10, the cap could be increased to 10%, and then 15%, to ensure that there are always at least 10 cities of a similar size.  On the other hand, if the population similarity is as high as 15%, query whether the city can actually be considered to be 'like' the nominated city.

### Project considerations

I took CS50 Python straight after CS50, and I'm pleased to say that what I learnt from CS50 meant that I breezed through most of the coursework and problem sets in CS50 Python relatively quickly.

However, because CS50 teaches you to build a web based and encourages you to go even beyond that, I felt that with the python course it would be better to confine it to python code access via the command line.  I have already started the CS50 web course and am some way through that so I hope to continue the front end learning in that course.

But I should acknowledge I can already see some of the limitations of command line programs comapred to web based apps in terms of providing better access to users of information or allowing a program to be more responsive to user input in the choices it offers users.  So while I appreciate that the project is somewhat hamstrung by being limited to python, it was a conscious decision so that I wouldn't go down a rabbit hole of researching and implement frameworks that would be beyond the core subject matter of this course.




