# 内置函数

from ex25 import *

# 1. sorted：排序并返回一个全新的list
a = [5,7,3,10,77]
b = sorted(a)
print(b)


str1 = "hello world! I'a a new python coder."
strArray1 = str1.split(' ')
print(strArray1)


print("first :" ,strArray1.pop(0))
print("last :",strArray1.pop(-1))
print("all :" , strArray1)

str2 = "All good things will be comming."
print("break_words : ",break_words(str2))
print("sort_sentence :",sort_sentence(str2))
print("print_first_and_last :",print_first_and_last(str2))
print("print_first_and_last_sorted :",print_first_and_last_sorted(str2))