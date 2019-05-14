# 打印，打印

formatter = "%r %r %r %r"

# 四个值分别是1，2，3，4
print(formatter % (1,2,3,4))

# 四个值分贝是 one two three four
print(formatter % ("one","two","three","four"))

print(formatter % (True,False,False,True))

print(formatter % (formatter,formatter,formatter,formatter))


# 为啥最后这个打印出的字符串既有单引号，又有双引号
print(formatter % (
	"I had this thing.",
	"That you could type up right.",
	"But it didn't sing.",
	"So I sad goodnight."
	))
