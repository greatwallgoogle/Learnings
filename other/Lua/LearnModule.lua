-- Module.lua
print('----learn to how to make module-----')

-- 定义一个名为ModuleT的模块,模块的本质就是一个table，内部包含变量和函数等
ModuleT = {}


-- 定义一个变量
ModuleT.constant = '这是一个常量'

-- 定义一个
function ModuleT.Fun1(  )
	print('这是一个公有函数')
end


local function Fun2()
	print('这是一个私有函数')
end


function ModuleT.Fun3( )
	Fun2()
end

return ModuleT

