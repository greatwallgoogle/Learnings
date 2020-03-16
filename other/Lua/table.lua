print('----table-----')


-- 直接初始化
tab1 = {}

-- 直接赋值
tab1['h'] = 'hhhhh'
print(tab1['h'])

-- 删除
tab1 = nil
print(tab1)


--test
mytable = {}
print('类型：'..type(mytable))
mytable['wow'] = "修改前"
mytable[1]= "Lua"
print("mytable 索引为 1 的元素是: ", mytable[1])
print("mytable 索引为 wow 的元素是: ", mytable["wow"])

print('\n-----按照索引遍历，使用ipairs')
for i,v in ipairs(mytable) do
	print(i,v)
end

print('\n-----按照key遍历，使用pairs')
for k,v in pairs(mytable) do
	print(k,v)
end


-- alternatetable和mytable的是指同一个 table,如果修改mytable的元素值，那么alternatetable的元素值也会改变
alternatetable = mytable
print("alternatetable 索引为 1 的元素是 ", alternatetable[1])
print("alternatetable 索引为 wow 的元素是 ", alternatetable['wow'])

alternatetable["wow"] = "修改后"
print("alternatetable 索引为 wow 的元素是 ", alternatetable['wow'])
print("mytable 索引为 wow 的元素是: ", mytable["wow"])


alternatetable = nil
print("alternatetable 是 ", alternatetable)
print("mytable 是 ", mytable)

-- 依然可以访问mytable
print("mytable 索引为 wow 的元素是 ", mytable["wow"])



print('----concat连接table内部元素,返回连接后的字符串')
table3 = {'fruit','apple','banana','orange'}
print(table.concat(table3)) -- fruitapplebanana

-- 指定元素之间的连接字符串
print(table.concat(table3,'-+'))  --fruit-+apple-+banana-+orange

-- 在起始索引元素之间添加指定字符串
print(table.concat(table3,' & ',2,4)) --apple & banana & orange


print('----调用insert插入元素:默认在末尾插入----')
table.insert(table3,"mango")
print(table3[5])

-- 在指定索引插入指定元素
table.insert(table3,2,'gray')
print(table3[2])

for k,v in pairs(table3) do
	print(k,v)
end


-- 调用remove从table中移除元素,默认移除最后一个
table.remove(table3)
print(table3[6])

print('\n---移除元素后打印表：')
for k,v in pairs(table3) do
	print(k,v)
end


table.remove(table3,2)
print('\n---移除第二个元素元素后打印表：')
for k,v in pairs(table3) do
	print(k,v)
end



print('\n\n-----调用sort排序:排序前')
fruits = {"banana","orange","apple","grapes"}
for i,v in ipairs(fruits) do
	print(i,v)
end


table.sort(fruits)
print('\n-----排序后')
for i,v in ipairs(fruits) do
	print(i,v)
end









