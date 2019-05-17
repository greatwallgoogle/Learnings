# 命名 变量 函数

# 使用def 关键字定义函数
def print_two(*args):
	arg1,arg2 = args
	print("print_two: arg1 :%r , arg2 :%r" %(arg1,arg2))


def print_two_again(arg1,arg2):
	print("print_two_again: arg1 :%r , arg2 :%r" %(arg1,arg2))


def print_one(arg1):
	print("print_one arg1 : %r" % arg1)


def print_none():
	print("===print_none===")


print_two("one","two")
print_two_again("zed","shaw")
print_one("first!")
print_none()
