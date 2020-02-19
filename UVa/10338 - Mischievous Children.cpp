#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,tam;
	unsigned long long fat,flag;
	string palavra;
	scanf("%d",&n);
	for (int j = 0; j < n; j++)
	{
		map<char,int>ocor;
		map<char,int>::iterator it;
		cin>>palavra;
		tam = palavra.size();
		fat = flag = 1;
		for (int i = 0; i < tam; i++)
		{
			ocor[palavra[i]]++;
			fat*=(flag);
			flag++;
		}	
		
		for (it = ocor.begin(); it!=ocor.end(); it++)
		{
			flag = 1;
			for (int i = 0; i < (it->second); i++)
			{
				flag*=(i+1);
			}
			fat/=flag;
		}
		printf("Data set %d: %llu\n",j+1,fat);
	}
}
