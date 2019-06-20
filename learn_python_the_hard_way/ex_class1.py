# self 代表类的实例，self 在定义类的方法时是必须有的，虽然在调用时不必传入相应的参数。
# 类函数的第一个参数必须是self

# 类变量定义：
# _foo：单下划线开头的表示是protected类型的变量
# __foo：双下划线开头的表示是private类型的变量
# __foo__：表示定义的是特殊方法，一般是系统定义名字

class Map(object):
	"""docstring for Map"""
	def __init__(self, arg):
		super(Map, self).__init__()
		self.arg = arg
		print("Map arg:",arg)
		print(self)
		print(self.__class__)

	# 析构函数，当对象不再被使用时，__del__方法运行
	def __del__(self):
		print("Map Del")

	def nextScene(self,sceneName):

		pass

	def openingScene(self):
		pass
		

class Engine(object):
	"""docstring for Engine"""
	def __init__(self, arg):
		super(Engine, self).__init__()
		self.arg = arg
		# 类的文档字符串
		print(self.__doc__)

	def play(self):
		pass


class Scene(object):
	"""docstring for Scene"""
	def __init__(self, arg):
		super(Scene, self).__init__()
		self.arg = arg
		print(self.__doc__)

	def enter(self):
		pass
		

# 表示继承自Scene
class Death(Scene):
	"""docstring for Death"""
	def __init__(self, arg):
		super(Death, self).__init__()
		self.arg = arg
		
		
	def enter(self):
		pass

# 表示继承自Scene
class CenterlCorridor(Scene):
	"""docstring for CenterlCorridor"""
	def __init__(self, arg):
		super(CenterlCorridor, self).__init__()
		self.arg = arg
		
	def enter(self):
		pass

# 表示继承自Scene
class LaserWeaponArmory(Scene):
	"""docstring for LaserWeaponArmory"""
	def __init__(self, arg):
		super(LaserWeaponArmory, self).__init__()
		self.arg = arg
		
	def enter(self):
		pass

# 表示继承自Scene
class TheBridge(Scene):
	"""docstring for TheBridge"""
	def __init__(self, arg):
		super(TheBridge, self).__init__()
		self.arg = arg

	def enter(self):
		pass

# 表示继承自Scene
class EscapePod(Scene):
	"""docstring for EscapePod"""
	def __init__(self, arg):
		super(EscapePod, self).__init__()
		self.arg = arg

	def enter(self):
		pass
		
		
# 创建实例
aMap = Map("CenterlCorridor")
aGame = Engine(aMap)
aGame.play()




