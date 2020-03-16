import random

from urllib.request import urlopen

import sys

WORD_URL = "http://learncodethehardway.org/words.txt"

WORDS = []
PHRASES = {
	"class %%%(%%%)":"Make a class name %%% that is-a %%%.",
	"class %%%(object):\n\tdef __init__(self,***)":
	 "class %%% has-a __init__that takes self and *** parameters.",
	"class %%%(object):\n\tdef ***(self,@@@)":
	 "class %%% has-a function named *** that takes self and @@@ parameters.",
	"*** = %%%()":
	 "Set *** to an ihnstance of class %%%.",
	"***.***(@@@)":
	 "From *** get the *** function,and call it with parameters self, @@@。",
	"***.*** = '***'":
	 "From *** get the *** attribute and set it to ’***‘."
}

if len(sys.argv) == 2 and sys.argv[1] == "english":
	PHRASE_FIRST = True
else:
	PHRASE_FIRST = False

for word in urlopen(WORD_URL).readlines():
	temp = word.strip()
	WORDS.append(temp.decode())


def convert(snippet, phrase):
	nCount = snippet.count("%%%")
	# random.sample(list,k):返回一个长度为k新列表，新列表存放list所产生k个随机不重复的元素
	listWords = random.sample(WORDS, nCount)
	print("nCount:",nCount)
	print("listWords:",listWords)

	#str.capitalize() : 表示将字符串的第一个字母大写，其他字母小写
	class_name = [w.capitalize() for w in listWords]
	print("class_name:",class_name)


	nCountStar = snippet.count("***")
	other_name = random.sample(WORDS, nCountStar)
	print("nCountStar:",nCountStar)
	print("other_name:",other_name)

	results = []
	parma_names = []

	for i in range(0,snippet.count("@@@")):
		param_count = random.randint(1,3)
		print("param_count:",param_count)
		randomList = random.sample(WORDS, param_count)
		print("randomList:",randomList)
		parma_names.append(', '.join(randomList))

	print("parma_names:",parma_names)

	for sentence in snippet,phrase :
		result = sentence[:]
		print("sentence:",sentence)
		for word in class_name:
			result = result.replace("%%%", word, 1)

		for word in other_name:
			result = result.replace("***", word, 1)

		for word in parma_names:
			result = result.replace("@@@", word, 1)

		results.append(result)

	return results

# keep going until they hit CTRL-D


list = [20, 16, 10, 5]
random.shuffle(list)
print("random :",list)

snippets = PHRASES.keys()

# 随机排列,'dict_keys' object does not support indexing
# random.shuffle(snippets)

for snippet in snippets:
	phrase = PHRASES[snippet]
	question, answer = convert(snippet, phrase)
	print("question:",question)


# try:
# 	while True:
		# snippets = PHRASES.keys()
		# random.shuffle(snippets)

		# for snippet in snippets:
		# 	phrase = PHRASES[snippet]
		# 	question, answer = convert(snippet, phrase)
		# 	print("question000:",question)
		# 	if PHRASE_FIRST:
		# 		question,answer = answer,question

		# 	print("question:",question)

		# 	input(">  ")
		# 	print("answer: %s\n\n" % answer)

# except EOFError:
# 	print("\nBye")
