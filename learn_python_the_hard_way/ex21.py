#函数返回值

def add(a,b):
	print("%d + %d = " % (a,b))
	return a + b


def subtract(a,b):
	print("%d - %d = " %(a,b))
	return a - b

def mutiply(a,b):
	print("%d * %d = " %(a,b))
	return a * b

def divide(a,b):
	print("%d / %d = " %(a,b))
	return a / b


c = add(3,5)
print("add: %d " % c)

d = subtract(3,5)
print("subtract: %d" %d)


e = mutiply(5,6)
print("mutiply : %d" % e)

f = divide(100,5)
print("divide: %d" % f)


what = add(c, subtract(d, mutiply(e, divide(f,2))))
print("The final result:%d" % what)


# def ：定义函数
# print : 打印日志
# from XX import YY ： 导入XX库的YY部分
# file = open(fileName) : 打开某个文件
# file.close() : 关闭文件
# file.read() : 读取文件内容
# file.truncate() : 清除文件内容
# file.readline() : 读取一行
# input("xxx") : 输入提示，并从接受从终端的输入
# int(xx) : 将xx转成int 类型
