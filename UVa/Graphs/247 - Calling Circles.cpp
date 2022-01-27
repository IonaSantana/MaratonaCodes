#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
typedef set<string> si;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> G,G1;
vi S, visited;
si ligacao;
set<string>::iterator it; 
map<string,int>mi;
map<int,string>im;
int V,flag;
stack<int>pilha;
void fillOrder(int u)
{
	visited[u] = 1;
	
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		int v = G[u][i];
		if(!visited[v])
		{
			fillOrder(v);
		}
	}
	pilha.push(u);
}

void dfs(int u)
{
	visited[u] = 1;
	if(flag)
		printf(", ");
	flag++;
	cout<<im[u];
	for (int i = 0; i < (int)G1[u].size(); i++)
	{
		int v = G1[u][i];
		if(!visited[v])
		{
			dfs(v);
		}
	}
}
int main()
{
	int cont,A,contador=1;
	string verifica,nome1,nome2;
	while (scanf("%d%d",&V,&A), V || A)
	{	
		if(contador > 1)
			puts("");
		G.assign(V+5, vi());
		G1.assign(V+5, vi());
		cont = 1;
		for (int i = 0; i < A; i++)
		{
			verifica = "";
			cin>>nome1>>nome2;
			verifica = nome1 + " " + nome2;
			
			if (!mi.count(nome1))
			{
				mi[nome1] = cont;
				im[cont] = nome1;
				cont++;
			}
			if (!mi.count(nome2))
			{
				mi[nome2] = cont;
				im[cont] = nome2;
				cont++;
			}
			
			if(ligacao.find(verifica) == ligacao.end())
			{
				G[mi[nome1]].push_back(mi[nome2]);
				G1[mi[nome2]].push_back(mi[nome1]);
				ligacao.insert(verifica);
			}		
		}
		printf("Calling circles for data set %d:\n",contador);
		contador++;
	    visited.assign(V+5, 0);

	    for(int i=1; i<=V; i++)
	    {
		  if(!visited[i])
		  {
			 fillOrder(i);
		  }
	    }
	    visited.assign(V+5, 0);
		while (!pilha.empty())
		{
			int n = pilha.top();
			pilha.pop();
			
			if(visited[n] == 0)
			{
				flag = 0;
				dfs(n);
				cout<<"\n";
			}		
		}
		im.clear();
		mi.clear();	
		ligacao.clear();
	}
}
