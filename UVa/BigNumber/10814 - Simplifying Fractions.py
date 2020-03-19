def gcd(a,b):
	if b==0:
		return a;
	return gcd(b, int(a%b));		

entrada = input();
n = int(entrada);

for i in range(n):
	entrada = input();
	x,y,z = entrada.split();
	x = int(x);
	z = int(z);
	g = int(gcd(x,z));
	print(x//g, "/", z//g);
	
