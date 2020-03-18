while True:
	try:
		soma = 0
		entrada = input();
		x,y = entrada.split();
		x = int(x);
		y = int(y);
		n = 1;
		
		while n <= x:
			soma = soma + (n*(y**n));
			n+=1;
			
		print(soma);
		
	except EOFError:
		break
