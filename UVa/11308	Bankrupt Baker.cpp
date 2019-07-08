#include <bits/stdc++.h>

using namespace std;
typedef pair<string,int> si;

bool ordena(si a,si b)
{
	if(a.second < b.second)
		return true;
	if(a.second > b.second)
		return false;
	if(a.first > b.first)
		return false;
	return true;			
}
int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	int n,t,qt,valor,m,b;
	string frase,ing,receita;
	map<string,int>ingredientes;
	vector<si> r;
	
	scanf(" %d",&t);
	getchar();
	for (int j = 0; j < t; j++)
	{		
		getline(cin,frase);
		scanf(" %d %d %d",&m,&n,&b);
		getchar();
		for (int i = 0; i < m; i++)
		{
			cin>>ing;
			scanf(" %d",&valor);
			getchar();
			ingredientes[ing] = valor;
		}	
		for(int k = 0; k < n; k++)
		{
			getline(cin,receita);
			scanf(" %d",&qt);	
			getchar();
			int aux = 0;
			for (int i = 0; i < qt; i++)
			{
				cin>>ing;
				scanf(" %d",&valor);
				getchar();
				aux += valor * ingredientes[ing];
			}
			//cout<<aux<<endl;
			if(aux <= b)
			{
				r.push_back(si(receita,aux));
			}	
		}
		sort(r.begin(), r.end(), ordena);
		int tam = frase.size();
		for (int i = 0; i < tam; i++)
		{
			if(frase[i] > 96)
			{
				frase[i] -= 32;
			}
		}
		cout<<frase<<endl;
		tam = r.size();
		if(!tam)
		{
			printf("Too expensive!\n");
		}
		else
		{
			for (int i = 0; i < tam; i++)
			{
				cout<<r[i].first<<endl;
			}
		}		
		printf("\n");
		r.clear();
		ingredientes.clear();
	}	
}
