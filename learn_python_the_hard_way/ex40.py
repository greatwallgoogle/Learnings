# 模块、类和对象

# Python是一门面向对象的编程语言

# 模块(module)：1. 包含一些函数和变量的python文件
#              2. 可以导入此文件
#              3. 可以用.操作符访问此模块的函数和变量
#              似乎有点像C++中的Util类，包含函数和全局变量、静态变量


import ex40_module

ex40_module.apple()
print("module var:",ex40_module.tangerine)


# 声明一个类
class MyStuff(object):
	"""docstring for MyStuff"""
	def __init__(self):
		super(MyStuff).__init__()
		self.tangerine = "And now a thousand years between."

	def apple(self):
		print("I am classy apples!")


# 实例化一个对象
thing = MyStuff()
thing.apple()
print("Class var:",thing.tangerine)


class Song(object):
	"""docstring for Song"""
	def __init__(self,lyrics,age):
		super(Song).__init__()
		self.lyrics = lyrics
		self.age = age

	def sing_me_a_song(self):
		print("Age:",self.age)
		for line in self.lyrics:
			print(line)


print('*' * 50)
happy_bday = Song(["Happy birthday to you",
					"I don't want to get sued",
					"So I'll stop right there"],
					22)
happy_bday.sing_me_a_song()

print('*' * 50)
bulls_on_parade = Song(["They rally around tha family",
	                    "With pockets full of shells"]
	                    ,25)
bulls_on_parade.sing_me_a_song()

		