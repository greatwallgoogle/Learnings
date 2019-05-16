# 读写文件

# open: 打开文件
# write: 写入文件
# close：关闭文件名
# truncate : 清除文件内容

from sys import argv

script,filename = argv
print("We're going to erase %r." % filename)
print("If you don't want that, hit CTRL-C(^C).")
print("If you do want that, hit RETURN.")

input(" ? ")

print("Opening the file...")
target = open(filename, 'w')


print("Truncating the file. Goodbye!")
target.truncate()

print("Now I'm going to ask you for three lines.")
line1 = input("line 1 :")
line2 = input("line 2 :")
line3 = input("line 3 :")

print("I' m goint to write these to the file.")


target.write(line1)
target.write("\n")

target.write(line2)
target.write("\n")

target.write(line3)
target.write("\n")

print("And finally, we close it.")
target.close()


print("The file's content is :")
target = open(filename)
print(target.read())
