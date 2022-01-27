#include <bits/stdc++.h>

using namespace std;

int main()
{
		int n,tam,vet[2010],pos;
		vector<int>a;
		
		scanf("%d",&n);
		for (int j = 0; j < n; j++)
		{
			a.clear();
			scanf("%d",&tam);
			for (int i = 0; i < tam; i++)
			{
				scanf("%d",&vet[i]);
			}
			for (int i = tam-1; i >= 0 ; i--)
			{
				a.push_back(vet[i]);
			}
			for (int i = 0; i < tam; i++)
			{
				a.push_back(vet[i]);
			}		
			vector<int>L;
			for (int i = 0; i < (int)a.size(); ++i)
			{
				pos = lower_bound(L.begin(),L.end(),a[i]) - L.begin();
				if(pos == (int)L.size()) L.push_back(a[i]);
				else L[pos] = a[i];										
			}	
			printf("%d\n",(int)L.size());	
			
		}			
}



                                            


                                            




