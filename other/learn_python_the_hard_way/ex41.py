# 面向对象

# class X(Y) ：表示定义一个叫X的类，此类继承自Y。

# 表示定义一个X类
class X(object):
	"""docstring for X"""

	# 定义一个__init__函数，此函数有两个参数
	def __init__(self,parma1):
		super(X).__init__()
		self.parma1 = parma1
		print("Init parma1:",self.parma1)

	# 定义一个M函数，此函数包含两个参数
	def M(self,J):
		print("X class ",J)
		
# 声明一个实例
foo = X('song')
# 调用M 函数
foo.M(10)

foo.k = "test"
print("foo.k = ",foo.k)
