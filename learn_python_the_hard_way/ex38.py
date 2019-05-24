#列表操作

ten_things = "Apples Oranges Crows Telephone Light Sugar"
print("Wait there are not 10 things in that list.Let's fix that.")

stuff = ten_things.split(" ")
more_stuff = ["Day","Night","Song","Frisbee","Corn","Banana","Gril","Boy"]

while len(stuff) != 10:
	next_one = more_stuff.pop() #pop表示取出列表最后一个元素，并将此元素从列表中移除
	print("Adding",next_one)
	stuff.append(next_one)
	print("There are %d items now." % len(stuff))

print("There we go :" ,stuff)
print("There more_stuff:",more_stuff)

print("stuff[1] :" ,stuff[1])
print("stuff[-1]:",stuff[-1]) #index = -1，表示访问最后一个元素
print("stuff.pop:",stuff.pop())
print("all stuff:",stuff)

 #表示获取从索引3的位置开始，截止到索引5，不包含索引5对应的值，区间为[3,5)
print("stuff[3:5] :" ,stuff[3:5])
print('=='.join(stuff)) #join(list)：表示在list的元素之间添加一个字符串
print('#'.join(stuff[2:5])) 

strVar = "@@"
list2Var = strVar .join(stuff[0:3])
print("list2Var:",list2Var)


#用法总结：
# 1. append(ele)：将ele元素追加到列表尾部
# 2. listVar[index]：可以通过索引访问元素，索引值为-1，表示访问最后一个元素
# 3. listVar.pop()：表示获取列表的最后一个元素，并将其从列表移除
# 4. listVar[startIndex: endIndex]：表示获取索引值[startIndex,endIndex)对应的元素，注意区间是左闭右开
# 5. listVar2 = strVar.join(list1Var) ：表示在list1Var的每个元素之间添加字符串strVar，并返回最新的列表
