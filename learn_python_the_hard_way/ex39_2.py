import hashmap

states = hashmap.new()
hashmap.set(states,"Oregon","OR")
hashmap.set(states,"Florida","FL")
hashmap.set(states,"California","CA")
hashmap.set(states,"New York","NY")
hashmap.set(states,"Michigan","MI")

cities = hashmap.new()
hashmap.set(cities,"CA","San Francisco")
hashmap.set(cities,"MI","Detroit")
hashmap.set(cities,"FL","Jacksonville")


hashmap.set(cities,"NY","New York")
hashmap.set(cities,"OR","Portland")

print('-' * 50)
print("NY state has:" , hashmap.get(cities,"NY"))
print("OR state has:" , hashmap.get(cities,"OR"))

print('-' * 50)
print("Michigan's abbreviation is :" , hashmap.get(state,"Michigan"))
print("Florida's abbreviation is :" ,hashmap.get(state,"Florida"))


print('-' * 50)
print("Michigan has :" , hashmap.get(cities,hashmap.get(state,"Michigan")))
print("Florida has  :" , hashmap.get(cities,hashmap.get(state,"Florida")))


print('-' * 50)
hashmap.printList(state)

print('-' * 50)
hashmap.printList(cities)


print('-' * 50)
state = hashmap.get(states,"Texas")

if not state:
	print("Sorry, no Texas.")

city = hashmap.get(cities,'TX',"Does not exist.")
print("The city for the state 'TX' is :",city)




