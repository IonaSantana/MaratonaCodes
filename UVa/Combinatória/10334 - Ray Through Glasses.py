k = 0;
num = [0] * 1010
while True:
	try:
		entrada = input();
		vai = int(entrada);
		f = 1;
		num[0] = 1;
		n = 1;
		while n <= vai:
			num[n] = num[n-1] + f;
			f = num[n-1];
			n+=1;
		print(num[vai]);
		
	except EOFError:
		break
