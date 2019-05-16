# 提示和传递

from sys import argv

script ,user_name ,gender = argv
promte = ">>"

print("Hi %s, I'm the %r script." % (user_name,script))
print("I'm a %r",gender)


print("Do you like me %s?" % user_name)
like = input(promte)

print("Where do you live %s?" % user_name)
live = input(promte)

print("What kind of computer do you have %?")
computer = input(promte)

print("""
	So, you said %r about liking me.
	You live in %r. Not sure where that is.
	And you have a %r computer.
	Nice.
	""" % (like,live,computer))