adict = {'beatles' : '5', 'rolling stones' : '9', 'pavement' : '33', 'dire straits' : '15'}
bdict = {'apples' : '11', 'oranges' : '3', 'pineapples' : '12', 'nectarines' : '15'}

print('')
print('Printing the contents of entire dictionaries')
print(adict)
print(bdict)

print("")
print("Printing the value, only, of the key 'beatles'")
print(adict['beatles'])

print("")
print("Printing the key, only -# Can't do this yet!")
print(adict['beatles'])



print("")
print("Printing the key value pairs of a dict via a for loop")
for bandname, value in adict.items():
    print(bandname, value)

print("")

x = adict['beatles'] + bdict['apples']
print(x)
x = int(adict['beatles']) + int(bdict['apples'])
print(x)

print("")

print("")
