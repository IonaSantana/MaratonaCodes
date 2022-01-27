n = input();
n = int(n);
while n!=0:
	mod = n%10;
	n = n//10;
	n = n - mod*5;
	if n%17==0: 
		print(1);
	else:
		print(0);
	n = input();
	n = int(n);
			

	
	
