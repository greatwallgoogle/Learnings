# 输入  python 3 中仅保留了input函数，可以输入任何类型输入，不过默认输出的是字符串

print("How old are you?")
age = input()
print("How tall are you?")
height = input()
print("How much do you weight?")
weight = input()

print("So,you're %s old, %s tall and %r heavy." %(age,height,weight))