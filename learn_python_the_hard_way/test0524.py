def calculateAB():
 	bArray = [7,8,9]
 	aArray = [0,1,2,3,4,5,6,7,8,9]
 	for b in bArray:
 		for a in aArray:
 			currentNum = a * 10 + b
 			div = int(currentNum / b)
 			yu = int(currentNum % b)
 			if div == 9 and yu == 6 :
 				print(a ,b)


#结果是78
calculateAB()