#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	int tam,n,soma;
	
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int vet[3];
		vet[0] = vet[1] = vet[2] = 0;
		cin>>s;
		tam = s.size();
		soma = 0;
		for (int j = 0; j < tam; j++)
		{
			soma+=(s[j]-48);
			vet[(s[j]-48)%3]++;
		}
		printf("Case %d: ",i+1);
		
		if (soma%3 == 0)
		{
			if (vet[0]%2)
			{
				puts("S");
			}else
			{
				puts("T");
			}
			
		}else
		{
			if(tam == 1)
				puts("S");
			else if(soma%3 == 1)
			{	
				if (vet[1] && (vet[0]%2 == 0))
				{
					puts("S");
				}else
				{
					puts("T");
				}					
			}else
			{
				if (vet[2] && (vet[0]%2 == 0))
				{
					puts("S");
				}else
				{
					puts("T");
				}
			}		
		}
	}
}
