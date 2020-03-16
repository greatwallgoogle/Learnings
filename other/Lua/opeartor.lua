print('----操作符-----')
print('算术运算符：+,-,*,/,%,-,^')
print('逻辑运算符：and, or, not')
print('关系运算符：>,<,>=,<=,==,~=')


print('----算数运算符----')

local n1 = 2
local n2 = 5

print(n1..' + '..n2..' = '..(n1 + n2))
print(n1..' - '..n2..' = '..(n1 - n2))
print(n1..' * '..n2..' = '..(n1 * n2))
print(n1..' / '..n2..' = '..(n1 / n2))
print(n1..' % '..n2..' = '..(n1 % n2))
print(n1..' ^ '..n2..' = '..(n1 ^ n2))

print('----关系运算符----')
if n1 == n2 then
	print(n1 ..' == '..n2)
else
	print(n1..' ~= '..n2)
end

if n1 > n2 then
	print(n1.." > "..n2)
else
	print(n1.." < "..n2)
end

if n1 ~= n2 then
	print(n1.." ~= "..n2)
else
	print(n1..' == '..n2)
end


local b1 = true
local b2 = false
if b1 and b2 then
	print('and..',b1,b2)
elseif b1 or b2 then
	print('or..',b1,b2)
end
if not(b1 and b2) then
	print('not..',b1,b2)
end

strval = [[
^
not
* /
+ -
> < >= <= == ~=
and 
or
]]

print('\n优先级(从高到低)：\n'..strval)



