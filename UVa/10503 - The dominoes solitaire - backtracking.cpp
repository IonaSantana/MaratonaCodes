#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
typedef vector<ii>vi;
vi pecas;
ii pecaL,pecaR;
int m,n;
bool aux,visitado[15];

bool domino(int ladoEsquerdo, int preenchido)
{
	if(preenchido == n && (ladoEsquerdo == pecaR.first))
	{
		return true;
	}	
	if(preenchido == n)
	{	
		return false;
	}
	for (int i = 0; i < m; i++)
	{
		if(!visitado[i] && pecas[i].second == ladoEsquerdo)
		{
			visitado[i] = 1;
			aux |= domino(pecas[i].first, preenchido + 1);
			visitado[i] = 0;
		}
		if(!visitado[i] && pecas[i].first == ladoEsquerdo)
		{
			visitado[i] = 1;
			aux |= domino(pecas[i].second, preenchido + 1);
			visitado[i] = 0;
		}
		
	}
	return aux;
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int l,r;
	while (scanf(" %d", &n), n)
	{		
		scanf("%d",&m);
		scanf("%d %d %d %d",&pecaL.first,&pecaL.second,&pecaR.first,&pecaR.second);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d",&l,&r);
			pecas.push_back(ii(l,r));
			visitado[i] = 0;
		}
		
		aux = 0;
		if(domino(pecaL.second,0))
			puts("YES");
		else
			puts("NO");	
		
		pecas.clear();	
	}
}

