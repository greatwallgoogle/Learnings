print('-------OOP------')
Account = {balence = 0}


-- 创建一个新的函数，此函数保存在Account对象的withdraw域
function Account.withdraw(n)
	Account.balence = Account.balence - n
	print("-------function "..Account.balence)
end


-- 回调
Account.withdraw(7)

------------------------简单应用,封装一个Shape类

-- 声明简单类s

Shape = {area = 0}
function Shape:new(o,side)
	-- body
	o = o or {}
	setmetatable(o,self)
	self.__index = self
	side = side or 0
	self.area = side * side;
	return o
end

function Shape:printArea( ... )
	-- body
	print("Shape 面积为：",self.area)
end

shape = Shape:new(nil,50)
shape:printArea()



--- 子类Square

Square = Shape:new()

function Square:new(o,side)
	o = o or Shape:new(o,side)
	setmetatable(o,self)
	self.__index = self
	return o
end

function Square:printArea( ... )
	-- body
	print("Square 面积：",self.area)
end

square = Square:new(nil,3)
square:printArea()


--- 子类Rectangle
Rectangle = Shape:new()

function Rectangle:new(o,length,breadth)
	-- body
	o = o or Shape:new(o)
	setmetatable(o,self)
	self.__index = self
	self.area = length * breadth
	return o
end

function Rectangle:printArea( ... )
	-- body
	print("矩形面积：",self.area)
end

r = Rectangle:new(nil,5,6)

-- 注意：访问方法一定要使用冒号!!!!!!!!
r:printArea()


Circle = Shape:new()

function Circle:new(o,side)
	o = o or Shape:new(o)
	setmetatable(o,self)
	self.__index = self
	self.area = 3.12415 * side * side
	return o
end

c = Circle:new(nil,5)
c:printArea()

