#include <bits/stdc++.h>

using namespace std;
int N,lis,lis_end;
vector<int>vet,L,L_id,P;

void reconstrucao_print(int end)
{
	int x = end;
	stack<int>s;
	for (;P[x] >= 0; x = P[x])
		s.push(vet[x]);
	
	printf("%d\n",vet[x]);
	
	for (; !s.empty(); s.pop())
		printf("%d\n",s.top());
	
}
int main()
{
	int tam;
	while (scanf("%d",&N)!=EOF)
	{	
		vet.push_back(N);
		P.push_back(0);
	}
	lis = lis_end = 0;
	tam = vet.size();
	for (int i = 0; i < tam; i++)
	{
		int pos = lower_bound(L.begin(),L.begin() + lis, vet[i]) - L.begin();
		
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
	printf("%d\n-\n",lis);
	reconstrucao_print(lis_end);
}
