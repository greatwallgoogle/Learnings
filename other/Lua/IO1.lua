print('-----learn io-----')

--[[
file = io.open('IO.lua','r')

io.input(file)

print(io.read())

io.close(file)

-- 写入文件,追加

file = io.open("IO.lua","a")

io.output(file)

io.write("\n-----hello lua script------")

io.close(file)

]]


-- 完全模式
file = io.open("IO.lua","r")

-- 读取文件
print(file:read())

-- 获取当前位置
print(file:seek())

-- 定位到文件头
print(file:seek("set"))

-- 定位到文件尾
print(file:seek("end"))

-- 当前位置
print(file:seek())

-- 关闭打开的文件
file:close()



-- 写入文件
file = io.open("IO.lua","a")

file:write("\n-- how are you ?")
-- 获取当前位置
print(file:seek())

file:close()

