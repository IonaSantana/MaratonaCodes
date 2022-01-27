#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,lis,lis_end,T;
	string numero;
	scanf(" %d ",&T);
	
	for (int j = 0; j < T; j++)
	{	
		if(j)
			puts("");
		vector<int>vet,P,L,L_id;
	
		while(getline(cin,numero), numero != "")
		{ 
			n = stoi(numero);
			vet.push_back(n);
			P.push_back(0);
		}
	
		int tam = vet.size();
		lis = lis_end = 0;
		for (int i = 0; i < tam; i++)
		{
			int pos = lower_bound(L.begin(), L.begin() + lis, vet[i]) - L.begin();
			
			if(pos == (int)L.size())
				L.push_back(vet[i]);
			else
				L[pos] = vet[i];
				
			if(pos == (int)L_id.size())
				L_id.push_back(i);	
			else
				L_id[pos] = i;
			
			P[i] = pos ? L_id[pos - 1] : -1;
			
			if(pos + 1 >= lis)
			{
				lis = pos + 1;
				lis_end = i;
			}		
		}
		printf("Max hits: %d\n",lis);
		int x = lis_end;
		stack<int>s;
		for (;P[x] >= 0; x = P[x])
			s.push(vet[x]);
		
		printf("%d\n",vet[x]);
		
		for (; !s.empty(); s.pop())
			printf("%d\n",s.top());
	}
}
