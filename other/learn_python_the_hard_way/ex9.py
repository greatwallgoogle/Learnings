# 打印，打印，打印

days = "Mon Tue Wed Thu Fri Sat Sun"

# 第一中方法：将一个字符串扩展成多行
months = "Jan\nFeb\nMar\nApr\nMay\nJun\nJuly\nAug"

print("Here are the days :",days)  # 等价于  print("Here are the days : %s" % days)

print("Here are the months : ", months) #等价于 print("Here are the months : %s" % months)


# 第二种方法：使用三引号输出任意行的字符串
print("""
	There's something going on here.
	With the three double-quotes.
	We'll be able to type as much as we like.
	Even 4 lines if we want, or 5, or6.
	""")


# for example

tabby_cat = "\tI'm tabbed in."
print("tabby_cat:",tabby_cat)
persian_cat = "I'm split\non a line."
print("persian_cat:",persian_cat)
backslash_cat = "I'm \\ a \\ cat."
print("backslash_cat:",backslash_cat)
fat_cat = '''
I'll do a list:
\t* Cat food
\t* Fishied
\t* Catnit\n\t* Grass
'''
print(fat_cat)



# 
# while True:
#	for i in ["/","-","|","\\","|"]:
#		print("%s\r" % i)
