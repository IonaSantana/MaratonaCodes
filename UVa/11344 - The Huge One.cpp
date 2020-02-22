#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,v[2100],tam,j,c,P,resp,pot,numerofinal,cont,m;
	bool ver[2100];
	string num,outro;
	scanf("%lld ",&n);
	for (int k = 0; k < n; k++)
	{
		cin>>num;
		cin.ignore();
		scanf("%lld",&m);
		for (int i = 0; i < m; i++)
		{
			scanf("%lld",&v[i]);
		}
		
		tam = num.size();
		for (int j = 0; j < m; j++)
		{	numerofinal = 0;
			cont = 0;
			for (int i = tam - 1; i >= 0; i--)
			{
				c = (num[i] - 48);
				P = cont;
				resp = 1;
				pot = 10;
				for (; P > 0; P/=2)
				{
					if(P % 2 == 1)
					{
						resp = (resp%v[j] * pot%v[j])%v[j];
					}
					pot = (pot%v[j] * pot%v[j])%v[j];
				}
				numerofinal = (numerofinal%v[j] + (c%v[j]*resp%v[j]))%v[j];
				cont++;
			}
			
			ver[j] = (numerofinal%v[j]);
		}	
		for (j = 0; j < m && !ver[j]; j++);
	
		if (j == m)
			cout<<num<<" - Wonderful.";
		else
			cout<<num<<" - Simple.";
		puts("");
	}	
}
