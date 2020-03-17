# ex34 : 访问列表元素
# 常用函数
# 声明列表：[]
# 索引法访问元素： list[index]
# 删除某个元素：del(list[index])
# 列表元素反向：list.reverse()
# 追加元素：list.append(ele)

animals = ['dog','pig','tiger','bear',3,4,5,6]
print("animals :",animals)

# 索引法访问列表中的值
dog = animals[0]
print("animals first ele:", dog)


# 使用方括号的形式截取列表
list2 = animals[1:5] #从索引为1的地方开始，读取（5-1）个元素
print("animals[1:5]:",list2)

# 追加元素
animals.append("chicken")
print("animals :",animals)

# 删除元素
print("---list2-----orign:" , list2)
del(list2[0]) 
print("---list2-----new : " ,list2)

# 反向元素
print("---reverse-----orign:" , list2)
list2.reverse()
print("---reverse-----new:" , list2)

# 移除列表中的某个元素
list2.pop()
print("---pop-----new:" , list2)


