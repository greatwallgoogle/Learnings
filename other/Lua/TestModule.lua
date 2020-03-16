
--[[
-- 打印出当前默认搜索的动态库(so)路径
print(package.cpath)

-- 打印当前默认的用于搜索.lua文件的路径
print(package.path)

package.path = package.path..";/Users/momo/Documents/workspace_lua/?.lua"
print(package.path)
]]


-- require(name):其中name代表包含指定模块的文件名
require("LearnModule")
print(ModuleT.constant)
print(ModuleT.Fun1)
