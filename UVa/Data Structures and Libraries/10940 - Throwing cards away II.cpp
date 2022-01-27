#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,n1,numero;
	
	while (scanf("%d",&n), n)
	{
		vector<int>bin;
		n1 = n;	
		while (n1)
		{
			bin.push_back(n1%2);
			n1/=2;
		}
		bin.erase(bin.begin() + (bin.size()-1));
		bin.insert(bin.begin(), 0);
		numero = 0;
		for (int i = 0, dois = 1; i < (int)bin.size(); i++,dois*=2)
		{
			numero += bin[i]*dois;
		}		
		if(numero)
			printf("%d\n",numero);
		else
			printf("%d\n",n);
	}
}
