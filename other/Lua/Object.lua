print("---面向对象-----")

Shape = {area = 0}

function Shape:new(o,side)
	-- body
	o = o or {}
	setmetatable(o,self)
	self.__index = self
	side = side or 0
	self.area = side * side
	return o
end

function Shape:printArea( ... )
	-- body
	print('面积是：',self.area)
end

s = Shape:new(nil,10)
s:printArea()

-- 子类
Trangle = Shape:new()

function Trangle:new(o,a,h)
	-- body
	o = o or Shape:new(o)
	setmetatable(o,self)
	self.__index = self
	self.area = 0.5 * a * h
	return o
end

function Trangle:printArea( ... )
	-- body
	print('三角形面积：',self.area)
end

t = Trangle:new(nil,10,20)
t:printArea()

--- 正方形
Square = Shape:new()

function Square:new(o,a)
	-- body
	o = o or Shape:new(o)
	setmetatable(o,self)
	self.__index = self
	self.area = a * a
	return o
end

function Square:printArea( ... )
	-- body
	print('正方形面积：',self.area)
end

s = Square:new(nil,6)
s:printArea()