print('----IO-------')

local n = 1
-- 以只读的方式打开文件
file = io.open("array.lua","r")


-- 设置默认输入文件为array.lua
io.input(file)


-- 输出文件第一行
print(io.read())


-- 关闭打开的文件
io.close(file)


print('可写文件')

-- 以附加的方式打开只写文件
file = io.open("array.lua","a")


-- 设置默认输出文件为array.lua
io.output(file)

-- 在文件最后一行添加文字
-- io.write('\n-----array.lua 文件末尾添加一行')


io.close(file)



print('\n\n----开始读取整个文件------start\n')
file = io.open("array.lua","r")

io.input(file)

-- 从当前位置开始，读取整个文件
print(io.read("*a"))

io.close(file)
print("----开始读取整个文件------end\n")



-- 
file = io.open("array.lua","r")
io.input(file)
-- 从当前位置开始，读取整个文件
print(io.read())

print(io.read("*|"))

io.close(file)

-- how are you ?
-- how are you ?
-- how are you ?
-- how are you ?
-- how are you ?
-- how are you ?