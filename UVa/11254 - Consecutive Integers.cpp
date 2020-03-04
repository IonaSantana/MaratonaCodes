#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,s,resp,teste,teste1;
	int tam;
	while (scanf("%lld",&n), n!=-1)
	{
		vector<int>p;
		s = sqrt(2*n);
		for (int i = s; i >= 1; i--)
		{
			if((2*n)%i == 0)
			{			
				p.push_back(i);
			}	
		}
		tam = p.size();
		for (int i = 0; i < tam-1; i++)
		{
			long long a = (2*n + p[i] - p[i]*p[i])/(2*p[i]);	
			resp = ((2*a+p[i]-1)*p[i])/2;
			if (resp == n)
			{
				teste = a;
				teste1 = a+p[i]-1;
				break;
			}												
		}
		
		if(resp == n)
			printf("%lld = %lld + ... + %lld\n",n,teste,teste1);
		else
			printf("%lld = %lld + ... + %lld\n",n,n,n);
	}
}
