print("---learn coroutine")


--1. coroutine.create(): 创建coroutine ，参数是一个函数，返回coroutine，一般配合resume用来唤醒函数调用

function Func1(param)
	print('协同程序 coroutine.create  '..param)
end

co = coroutine.create(Func1)

--2. coroutine.resume():唤醒函数调用
local status,value = coroutine.resume(co,'hello coroutine')
print(status,value)
 print('-------\n\n')

--3.coroutine.status()：查看coroutine的状态。一共有dead/suspend/running三种状态
print(coroutine.status(co)) --dead


print('-----------')

--4. coroutine.wrap():创建coroutine，参数是一个函数，返回一个函数。和create功能一致,但是不用与resume配合使用
co2 = coroutine.wrap(
	function (p)
		print('协同程序 coroutine.wrap  '..p)
	end
)

co2('Lua coroutine')


print('----------------')

--5.coroutine.yield():表示coroutine挂起，配合resume使用会有很多种效果
--6.coroutine.running():获取正在跑的coroutine，一个coroutine就是一个线程，当使用running时，就是返回一个coroutine的线程号
co3 = coroutine.create(
	function()
		for i=1,10 do
			print(i)
			if i == 3 then
				print(coroutine.status(co3))
				print(coroutine.running())
			end
			coroutine.yield()
		end
	end
)

coroutine.resume(co3)
coroutine.resume(co3)
coroutine.resume(co3)


print(coroutine.status(co3))
print(coroutine.running())

print('--------------------')

function foo(a)
	print('foo 函数输出 ',a)
	return coroutine.yield(2 * a)
end

co4 = coroutine.create(
	function ( a,b )
		print('第一次协同程序执行输出',a,b)
		local r = foo(a + 1)

		print('第二次协同程序执行输出',r)
		local r,s = coroutine.yield(a + b, a - b)

		print('第三次协同程序执行输出',r,s)
		return b, "结束协同程序"
	end
) 

print('main',coroutine.resume(co4,1,10))

print('--------分割线------------')
print('main',coroutine.resume(co4,'p'))

print('--------分割线------------')
print('main',coroutine.resume(co4,'x','y'))

print('--------分割线------------')
print('main',coroutine.resume(co4,'x','y'))



--调用resume，将协同程序唤醒,resume操作成功返回true，否则返回false；
print('-----------')
print('000')
