k = 0;
num = [0] * 110
while True:
	try:
		entrada = input().split()
		for l in entrada:
			l = int(l)
			if l == -999999:
				maior = prod = num[0]
				for i in range(k):
					prod = 1
					for  j in range(i, k):			 
						prod *= num[j]
						maior = max(maior,prod)	
						if prod == 0: break										
																		
				print(maior)
				k=0;
			else:
			   num[k] = l
			   k += 1	
	except EOFError:
		break


