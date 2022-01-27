#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>ii;
typedef pair<int,pair<int,int>>iii;
typedef vector<iii>viii;
viii edge;
int N,pai[1000000],tam[1000000];
int main()
{
	int custo,l1,l2,soma = 0,k,m;
	scanf("%d",&N);
	for (int i = 0; i < N-1; i++)
	{
		scanf("%d%d%d",&l1,&l2,&custo);			
		soma += custo;
	}	
	scanf("%d",&k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d%d",&l1,&l2,&custo);			
		edge.push_back(iii(custo,ii(l1,l2)));
	}
	scanf("%d",&m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d",&l1,&l2,&custo);			
		edge.push_back(iii(custo,ii(l1,l2)));
	}
	
	for (int i = 0; i < k+m+1; i++)
	{
		pai[i] = i;
		tam[i] = 1;
	}
	
	

}
