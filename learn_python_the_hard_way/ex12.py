# 提示别人,即给input函数指定参数用于提示
# 重写ex11.py的内容

y = input("Name? ")
print(y)
# ------
print("----------")
age = input("How old are you ?")
height = input("How tall are you ?")
weight = input("How much do you weight?")

print("So,you are %r old, %r tall and %r heavy." % (age,height,weight))


# 在终端输入pydoc input，查看此函数的API简介
# 然后输入q退出pydoc