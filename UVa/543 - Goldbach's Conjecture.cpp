#include <bits/stdc++.h>

using namespace std;
bitset<10000001>bs;
int limite = 10000000;
vector<int>primos;

void crivo()
{
	bs.set();
	bs[0] = bs[1] = 0;
	
	for (long long i = 2; i <= limite; i++)
	{
		if (bs[i])
		{
			primos.push_back(i);
			for (long long j = i*i; j <= limite ; j+=i)
			{
				bs[j] = 0;
			}			
		}
	}	
}
int main()
{
	int n;
	crivo();
	primos.erase(primos.begin());
	while (scanf("%d",&n), n!=0)
	{
		int on,pos = lower_bound(primos.begin(), primos.end(), n) - primos.begin();
		if(primos[pos]==n || n%2)
		{
			puts("Goldbach's conjecture is wrong.");
		}else
		{
			bool flag = 1;
			int pos1;
			pos--;
			while (flag)
			{
				on = n - primos[pos];
				pos1 = lower_bound(primos.begin(), primos.end(), on) - primos.begin();
				if(on != primos[pos1])
				{
					pos--;
					if(pos==-1)
						break;
				}else
				{
					flag = 0;
				}
			}		
			if(flag)
				puts("Goldbach's conjecture is wrong.");
			else
				printf("%d = %d + %d\n",n,on,primos[pos]);
		}	
	}

}
