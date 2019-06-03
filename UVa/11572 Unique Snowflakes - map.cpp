#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int T,N,f,tam = 0,k,ultimok;
	map<int,int>floquinho;
	map<int,int>::iterator it;
	vector<int>v;
	scanf("%d",&T);
	for (int i = 0; i < T; i++)
	{
		tam = 0;
		scanf("%d",&N);
		for(int j = 0; j < N; j++)
		{
			scanf("%d",&f);
			v.push_back(f);
			floquinho[f] = -1;
		}
		k = 0;
		ultimok = k;
		while(k < N)
		{
			if(floquinho[v[k]] >= ultimok && floquinho[v[k]] < k)
			{
				tam = max(tam, k - ultimok);
				ultimok = k = floquinho[v[k]]; 	
				ultimok++;		 			
			}
			floquinho[v[k]] = k;
			k++;
		}	
		tam = max(tam,N  - ultimok);		
		printf("%d\n",tam);
		floquinho.clear();
		v.clear();
	}
}	


