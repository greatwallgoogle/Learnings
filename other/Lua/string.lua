print('-------string--------')

local strValue1 = 'Abs'

print('将字符全部转化为大写：string.upper()')
print(string.upper(strValue1))

print('\n')
print('将字符全部转化为小写：string.lower()')
print(string.lower(strValue1))

print('\n')
print('替换指定个数的指定字符')
-- a表示待替换的字符，z表示将要替换为的字符，最后一个数字表示替换次数
print(string.gsub('aaaafffaa','a','z',3))


print('\n查找字符串，并返回其起始和终止索引')
print(string.find('hello world','world'))


print('\n反转字符串')
print(string.reverse('hello lua'))

print('\n格式化字符串')
print(string.format('the value is %d',4))

print('\n计算字符串长度')
print(string.len('hello'))


print('\n返回n个字符串')
print(string.rep('Hello',3))


print('\n匹配字符串 -find')
local str = "Deadline is 30/05/1999, firm"
local parttenr = "%d%d/%d%d/%d%d%d%d"
print(string.find(str,parttenr))
print(string.sub(str,string.find(str,parttenr)))


print('\n匹配字符串 -gmatch')


