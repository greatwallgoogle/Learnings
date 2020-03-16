print("-----错误处理----")


function ADD(a,b)
	assert(type(a) == "number","a不是一个数字")
	print("--0000000-----"..a+b)
	-- 终止正在执行的函数并打印日志信息
	-- error("error message log",2) 
end

ADD(2,2)


-- pcall函数可以通过包装需要执行代码以用来处理错误，接受一个函数及要传递给函数的参数
pcall(ADD,5,5)

-- xpcall函数接受第二个参数——错误处理函数，可以用来设置额外的错误信息

function func1()
	-- body
	n = n/nil
end


function fun1Error(error)
	print("fun1Error   error",error)
end
xpcall(func1,fun1Error)