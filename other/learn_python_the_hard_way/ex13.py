# 参数、解包 、变量

# 导入sys模块的argv部分，此声明不会把整个sys模块导入当前命名空间，只会将sys的argv部分导入
from sys import argv

script, first, second, third = argv

firstTemp = input(first + " : ")
first = first + ". " + first + " has " + firstTemp + " . "



print("The script is called :",script)
print("Your first variable is :",first)
print("Your second varialbe is :",second)
print("Your third variable is:",third)


# 在终端输入 python ex13.py first 2nd 3rd
# 得到：
# The script is called : ex13.py
# Your first variable is : first
# Your second varialbe is : 2nd
# Your third variable is: 3rd