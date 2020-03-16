# sorted 可以对所有可迭代的对象进行排序操作，并返回一个全新的list。
# """ xxx """ ：xxx被称作文档注释，可以通过help(ex25)查看。

def break_words(stuff):
	"""This function will break up words for us."""
	words = stuff.split(' ')
	return words

def sort_words(words):
	"""Sorts the words."""
	return sorted(words)

def print_first_word(words):
	"""Prints the first word after popping it off."""
	word = words.pop(0)
	return word

def print_last_word(words):
	"""Prints the last word ater popping it off."""
	word = words.pop(-1)
	return word

def sort_sentence(sentence):
	"""Task in a full sentence and returns the sorted words."""
	words = break_words(sentence)
	return sort_words(words)

def print_first_and_last(sentence):
	"""Prints the first and last words of the sentence."""
	words = break_words(sentence)
	first = print_first_word(words)
	last = print_last_word(words)
	return first,last


def print_first_and_last_sorted(sentence):
	"""Sorts the words then prints the first and last one."""
	words = sort_sentence(sentence)
	first = print_first_word(words)
	last = print_last_word(words)
	return first,last

# -----------------------------说明-------------------------

# 在终端输入python，进入python环境
# 输入  import ex25
# 输入  sentence = "All good things will be comming."
# 输入  ex25.break_words(sentence)
# 终端输出的结果是：['All', 'good', 'things', 'will', 'be', 'comming.']
# 以此类推，调用ex25中的函数

# 可以输入help(ex25)命令查看此文件的API说明。
# 也可以输入help(ex25.break_words)命令查看具体的函数功能，此处查询的是break_words函数。
# 输入q 字母，退出help状态

# 最后通过quit()函数退出python环境。