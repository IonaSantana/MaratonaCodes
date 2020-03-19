import math
while True:
	try:
		flag = 0;
		entrada = input();	
		primo = int(entrada);
		raiz = int(math.sqrt(primo));
		for i in range(2,raiz+1):
			if primo%i==0:
				flag = 1;
				break;
		
		if flag == 0:						
			flag = 0;
			a = entrada[::-1];
			primo = int(a);
			raiz = int(math.sqrt(primo));
			for j in range(2,raiz+1):
				if primo%j==0:
					flag = 1;
					break;
			
			if flag == 0 and a!=entrada:
				print(entrada, "is emirp.");
			else:
				print(entrada, "is prime.");
		
		else:
			print(entrada, "is not prime.");
				
	except EOFError:
		break
