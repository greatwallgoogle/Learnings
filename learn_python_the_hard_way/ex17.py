# 更多文件操作
# exists(file_name) : 判断文件是否存在

from sys import argv
from os.path import exists

script, from_file ,to_file = argv

from_file_open = open(from_file)
from_file_data = from_file_open.read()

print("Copying from %s to %s." % (from_file,to_file))
print("The input file is %d bytes long." % len(from_file_data))
print("Does the output file exist? %r " % exists(to_file))

to_file_open = open(to_file,'w')
to_file_open.write(from_file_data)

from_file_open.close()
to_file_open.close()