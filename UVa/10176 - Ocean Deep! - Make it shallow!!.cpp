#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s = "",o;
	unsigned long long num,cont,mod = 131071,P,c,resp,pot;
	while (cin>>o)
	{
		if(o[o.size()-1] != '#')
		{
			s+=o;
		}
		else
		{	
			s+=o;
			num  = cont = 0;
			for (int i = s.size()-2; i >= 0; i--)
			{
				c = s[i] - 48;
				P = cont;
				resp = 1;
				pot = 2;
				if(c)
				{
					for (; P > 0; P/=2)
					{
						if(P % 2 == 1)
						{
							resp = (resp%mod * pot%mod)%mod;
						}
						pot = (pot%mod * pot%mod)%mod;
					}
					num = (num + resp)%mod;
				}
				cont++;
			}
			if(num%mod == 0)
				puts("YES");
			else
				puts("NO");
			
			s = "";
		}		
	}
}
