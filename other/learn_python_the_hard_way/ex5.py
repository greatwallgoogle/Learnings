# 更多变量的打印——格式化字符串

my_name = "Zed A. Shaw"
my_age = 35
my_height = 74 # inches
my_weight = 180 #lbs
my_eyes = 'Blue'
my_teeth = 'White'
my_hair = 'Brown'

print("Let's talk about %s." % my_name)
print("He's %d inches tall." % my_height)
print("He's %d pounds heavy." % my_weight)
print("Actually that's not too heavy.")

# Note :two params
print("He's got %s eyes and %s hair." % (my_eyes , my_hair))
print("His teeth are usually %s depending on the coffee." % my_teeth)

print("If I add %d %d , and %d I get %d." % (my_age,my_height,my_weight,my_age + my_height + my_weight))


# Python中所有的格式化字符
# %s ：字符串（采用str()的显示方式）
# %r ：字符串（采用repr()的显示方式）
# %c ：单个字符
# %b ：二进制证书
# %d ：十进制整数
# %i ：十进制整数
# %o ：八进制整数
# %x ：十六进制整数
# %e ：指数（基底为e）
# %E ：指数（基底为E）
# %f ：浮点数
# %F ：浮点数
# %g ：指数或浮点数
# %G ：指数或浮点数
# %% ： 字符“%”


# %r 和 %s不同之处：%r是调试用的；%s 才是输出显示用的。

x = "There are %d types of people." % 10
print("%r"%x)  # 结果是：'There are 10 types of people.'---多个单引号
print("%s"%x)  # 结果是：There are 10 types of people.