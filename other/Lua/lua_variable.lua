print('--lua有三种作用域的变量：全局变量、局部变量、表中的域--\n')
print('lua中默认的变量是全局变量，除非变量名之前使用了local关键字，此关键字表示当前变量是局部变量\n')

a = 5 -- 全局变量--
local  b = 1 --局部变量--


function test( ... )
	d = 15 -- 即便是在函数内部声明的变量，此变量也是全局变量--
	local c = 10 --局部变量--
end

test() --执行此函数之后，表示声明了全局变量d,如果不执行此函数，则d = nil
print(d,c)

print('--同时给多个变量依次赋值\n')
m,n = 5, 4 * 2
print(m,n)


print('---交换变量--\n')

x ,y = 2,1
print('交换之前：'..x,y)

x,y = y,x
print('交换之后：'..x,y)


x,y,z = 1,2,3,4 --4被丢弃---
print(x,y,z)

x,y,z = 3,4 --z被赋值为nil--
print(x,y,z)


--a,b = fun() 表示函数fun返回两个值，第一个值赋值给a,第二个付给b

print('for循环:数值for循环')
--[[
for var = exp1,exp2,exp3 do
	--body
end

表示变量var从exp1变到exp2，每次步进为exp3,exp3可省略，默认为1
]]--

for var = 1,20,5 do
	print(var)
end

print('for循环:泛型for循环')
a = {"one", "two", "three"}
for i,v in ipairs(a) do
	print(i,v)
end



print('if-else/ if-elseif\n')
a = 10
if a < 20 then
	print('a < 20')
else 
	print('a >= 20')
end


if a < 5 then
	print('a < 5')
elseif a <= 10 then
	print('a > 5 && a <= 10 \n')
else
	print('a > 10\n')
end

