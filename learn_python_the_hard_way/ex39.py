#字典

#1. 初始化一个字典变量
stuff = {"name":"Zed", "age":39, "height":6 * 12 + 2}
print("dict:",stuff)

#2. 访问某个键对应的值:dict[key]
print("stuff[name]:",stuff["name"])

# 通过get函数访问某个键对应的值：dict.get(key)
var1 = stuff.get('height')
print('stuff[height] :' ,var1)

#3. 添加元素
stuff["city"] = "San Francisco"
stuff["1"] = "Wow"
print("new  stuff:",stuff)

#4. 删除某个键值对
del(stuff["1"])
print("del stuff[1]:",stuff)

# 得到字典的所有键值对（存放在列表中）
print(stuff.items())

#------------------------------------

# create a mapping of state to abbreviation
states = {
	'Oregon':'OR',
	'Florida':'FL',
	'California':'CA',
	'New York':'NY',
	'Michigan':'MI'
}

# crate a basic set of states and some cities in them
cities = {
	'CA':'San Francisco',
	'MI':'Detroit',
	'FL':'Jacksonville'
}

# add some more cities
cities['NY'] = 'New York'
cities['OR'] = 'Portland'

# print out some cities
print('-' * 50) # str * n ：表示生成一个由n个str组成新的字符串
print("NY State has:",cities['NY'])
print("OR State has:",cities['OR'])

# print out some states
print('-' * 50) # str * n ：表示生成一个由n个str组成新的字符串
print("Michigan's abbreviation is :",states['Michigan'])
print("Florida's abbreviation is :",states['Florida'])

print('-' * 50) # str * n ：表示生成一个由n个str组成新的字符串
print("Michigan has :" ,cities[states['Michigan']])
print("Florida has :",cities[states['Florida']])

print('-' * 50)
for state,abbrev in states.items():
	print("%s is abbreviated %s " % (state,abbrev))

print('-' * 50)
for abbrev,city in cities.items():
	print("%s is abbreviated %s " % (abbrev,city))

print('-' * 50)
for state,abbrev in states.items():
	print("%s is abbreviated %s and has city %s " % (abbrev,city,cities[abbrev]))


print('-' * 50)
state = states.get('Texas')

if not state:
	print('Sorry. no Texas.')

city = cities.get('TX',"Does Not Exist.")
print("The city for the state 'TX' is : %s" % city)
