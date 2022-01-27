n = input();
n = int(n);

for i in range(n):
	x,y = input().split();
	inx = int(x[::-1]);
	iny = int(y[::-1]);
	
	soma = inx + iny;
	soma = str(soma);
	soma = soma[::-1];
	soma = int(soma);
	print(soma);
	
	
