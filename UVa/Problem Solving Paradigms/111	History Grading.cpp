#include <bits/stdc++.h>

using namespace std;

int main()
{		
		//~ freopen("in","r",stdin);
		//~ freopen("out","w",stdout);
		int tam,pos,a[30],vet[30],teste[30];
		string n; 
		map<int,int>ma;
		while(getline(cin,n))
		{		
			if(n.size() <= 2)
			{
				ma.clear();		
				tam = stoi(n);
				
				for (int i = 1; i <=tam; i++)
				{
					scanf(" %d",&teste[i]);
				}	
        getchar();        	
			}	
			else	
			{	
				stringstream f(n);
				int j = 1;
				while(f>>a[j++]);		

				for (int i = 1; i <= tam; i++)
				{
					ma[a[i]] = i;
				}	
				for (int i = 1; i <= tam; i++)
				{
					vet[i] = ma[i];
				}		
				vector<int>L;
				for (int i = 1; i <= tam; i++)
				{
					pos = lower_bound(L.begin(),L.end(), teste[vet[i]]) - L.begin();
					
					if(pos == (int)L.size()) L.push_back(teste[vet[i]]);
					else L[pos] = teste[vet[i]];										
				}	
				printf("%d\n",(int)L.size());	
			}
		}			
}
