print('1.------fucntion demo----')

function Factrical( n )
	if n == 0 then 
		return 1
	else
		return n * Factrical(n-1)
	end
end


print(Factrical(4))


print('2.--------返回值-------')
function GetMax( value1,value2 )

	if value1 > value2 then
		result = value1
	else
		result = value2
	end
	return result
end

print('max = '..GetMax(5,10))
print('max = '..GetMax(5,2))


print('3.----将函数作为参数传递------')

printFunc = function ( x )
	print('----print function:'..x)
end

-- 函数可作为参数使用，这点非常有用，这样可以根据不同的功能定制不同的functionPrint，达到“多态”的效果!!!!
function LearnFunc( x,y,functionPrint)
	result = x + y
	functionPrint(result)
end

printFunc(10)
LearnFunc(5,10,printFunc)


print('4.-----多返回值------')
ns,ne = string.find('www.helloworld.com','helloworld')
print('start = '..ns..'  end = '..ne) -- 表示从5开始，截止到14；注意：Lua中的索引从1开始！！！！

function MultReturnValue(a)
	local maxValue = a[1]
	local minValue = a[1]
	for i,v in ipairs(a) do
		if v > maxValue then
			maxValue = v
		elseif v < minValue then
			minValue = v
		end
	end
	return maxValue,minValue
end


a = {1,4,7,12,10}
maxValue,minValue = MultReturnValue(a)
print('max = '..maxValue..'  min = '..minValue)


print('5.-------可变参数-------')
function Add( ... )
	local s = 0
	local tab1 = {...}
	for i,v in ipairs(tab1) do
		s = s + v
	end
	return s
end

print(Add(3,4,5,6,7,8,9))


print('6.------获取可变参数长度------')
function GetNum( ... )
	local  talb2 = {...}
	local length1 = select('#',...)
	print('calculate length method1 = '..length1)

	local length2 = #talb2
	print('calculate length method2 = '..length2)
end

print(GetNum(3,4,5))

