# 函数和变量时

def cheese_and_crackers(cheese_count, boxes_of_crackers):
	print("You have %d cheeses!" % cheese_count)
	print("You have %d boxes of crackers!"%boxes_of_crackers)
	print("Man that's enough for a party!")
	print("Get a blanket.\n")
	pass

print("We can just give the function numbers directly:")
cheese_and_crackers(20,30)


amount_of_cheese = 20
amount_of_cracker = 36
cheese_and_crackers(amount_of_cheese,amount_of_cracker)


print("We can even do math inside too:")
cheese_and_crackers(10 + 20, 30 + 5)

print("And we can combine the two ,variables and math:")
cheese_and_crackers(amount_of_cheese + 100,amount_of_cracker + 1000 )


print("Or , we can use variables from out script:")
amount_of_cheese = int(input("> cheese count:"))
amount_of_cracker = int(input("> cracker count: "))
cheese_and_crackers(amount_of_cheese,amount_of_cracker)

