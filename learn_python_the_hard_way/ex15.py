#读文件

# 打开文件：open
# 读取文件内容: file.read()

from sys import argv

script ,filename = argv

fileContent = open(filename)
print("%r  content is :" % (filename))
print(fileContent.read())


newfilename = input("> Please input filename : ")
newFileContent = open(newfilename)

print("********** the file conent **********")
print(newFileContent.read())



