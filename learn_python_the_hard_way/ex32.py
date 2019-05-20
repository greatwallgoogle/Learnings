# 循环和列表

# list初始化：将数据放入[ ]之间，用逗号分隔
# ele = []; --声明一个空列表
# ele.append(x); 向列表尾部添加一个元素x
# for i in list : 遍历列表list
# 列表中可以存放不同类型的元素
# range(start,end) :表示生成一个列表，其元素为从start开始，最后一个元素为（end - 1），即区间为[start,end)。
# 可以使用[index]访问元素

hairs = ["brown","blond","red"]
eyes = ["brown","blue","green"]
weights = [1,2,3,4]

print("hairs:" , hairs)
print("eyes:" ,eyes)
print("weights: ",weights)


the_count = [1,2,3,4,5]
#pear : 梨
# apricot: 杏
fruits = ['apples','oranges','pears','apricots']
change = [1,'pennies',2,'dimes',3,'quaters']

for number in the_count:
	print("This is count %d" % number)

for fruit in fruits:
	print("A fruit of type:%s" % fruit)

for x in change:
	print("I got %r" % x)


elements = []

for x in range(0,6):
	print("Adding %d to the list." % x)
	elements.append(x)

for x in elements:
	print("Element was : %d" % x)


elements2 = range(1,10)
print("elements2 :" ,elements2)


# 定义一个两层列表
list1 = [[1,2,3],['a','b'],["hello","world"],["Monday",10]]
print("list1 :" ,list1)

# 可以使用[]访问元素
print("list index1 :" , list1[0])
print("list index2 :" , list1[1])

# 遍历每个元素值
for x in list1:
	print("x : " , x)
	for y in x:
		print("y : ",y)
	print("================")


# 通过索引循环
for index in range(len(list1)):
	print("current ele:", list1[index])
	for index2 in range(len(list1[index])):
		print("current ele 2:" , list1[index][index2])
	print("**********************")


