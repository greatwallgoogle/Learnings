--shilt+command+B:重新编译运行---
--command+B:运行--

print("hello lua world!")


--单行注释--

--[[
多行注释
多行注释
]]--


--Lua中的变量默认为全局变量--

b = 10 --全局变量--
print('b =',b)

--如果想删除一个全局变量，直接将其赋值为nil即可--
b = nil
print(b)


--Lua支持八中数据类型：nil/boolean/number/string/userdata/function/thread/table--
print(type('Hello World'))
print(type(10))
print(type(true))
print(type(print))
print(type(type))
print(type(nil))
print(type(type(x)))


print("-------------------------")

--table使用--

--1. table声明,table的key可以是字符串和数字,table有点类似map, 同样跟map类似，内部元素是无须的--
tab1 = {key1 = "val1",key2 = "val2","val3","val4"}

--2.执行for循环---
for k,v in pairs(tab1) do
	print("k = "..k.."			v = "..v)
end

tab2 = {}
for k,v in pairs(tab2) do
	print(k,v)
end

--table中的数据类型可以不一致--
print("-------table test------")
tab2["key3"] = "value3"
tab2[10] = 10
for k,v in pairs(tab2) do
	print(k,v)
end


print("--------从头遍历所有元素，索引从1开始-----")

--lua中默认的索引从1开始--
tab3 = {"vv1","vv2","vv3","vv4"}
for k,v in pairs(tab3) do
	print("index = "..k.." value = "..v)
end

print('----------------------')

--boolean + if/else--
if false or nil then
	print("false or nil is true")
else
	print("false and nil is false")
end

--lua仅支持一种数字类型number，表示double类型--
print(type(2))
print(type(2.2))
print(type(2e+1))


--lua中字符串用单引号或双引号扩住--
print(type("hello1"))
print(type('world1'))


--可以使用[[  ]]表示 “一块字符串”--
strTest = [[
void main()
{
	print("hello C++!");
}
]]
print(strTest)


print('--对字符串进行算数运算时，Lua会将字符串转化为数字--\n')
print('2' + 6) --输出8.0--

print("3" + "10") --输出13.0--

print("4 + 12") -- 输出字符串《 4 + 12 》--

print("3" * '4') --输出12.0--


print('--使用..拼接字符串--\n')
print("hello ".." world")


print('--计算字符串的长度：#--\n')
strLeng = "hello world"
print("length:"..#strLeng)



print('---------function ---------\n')
function factoria( n )
	if n == 1 then
		return 1
	else
		return n * factoria(n - 1)
	end
end

print(factoria(4))


print('----函数可以存在变量里-----\n')
factoria2 = factoria
print(factoria2(4))


print('-----匿名函数可以作为函数参数-------\n')
function TestMethod1(tableVar,fun)
	for k,v in pairs(tableVar) do
		fun(k,v)
	end
end

tableVar1 = {key1 = "value1",key2 = "value2",key3 = "value3"}
TestMethod1(tableVar1,
	function(k,v )
		print(k,v)
	end)


print('--userdata 是一种用户自定义数据，用于表示一种由应用程序或 C/C++ 语言库所创建的类型，可以将任意 C/C++ 的任意数据类型的数据（通常是 struct 和 指针）存储到 Lua 变量中调用。--')



