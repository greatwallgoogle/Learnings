# while循环

elements = ['apples','branana','pears','oranges','apricots']
i = 0
while i < len(elements):
	print("current fruit:",elements[i])
	i = i + 1

i = 0
numbers = []
while i < 6:
	numbers.append(i)
	i = i + 1
	print("Numbers now :",numbers)


print("The numbers :")
for x in numbers:
	print(x)


# 定义一个函数，并将列表返回
def while_test(n):
	i = 0
	elements = []
	while i < n:
		elements.append(i)
		i = i + 1

	return elements


testData = while_test(10)
print("testData :" ,testData)