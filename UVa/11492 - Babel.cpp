#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
typedef vector<iii>vi;
#define inf 0x3f3f3f3f
#define vertice second
#define tamanho first.first
#define letra first.second 
vi g[5020];

int d(int u,int volta)
{
	//~ vector<int>dist(5020,inf);
	int dist[5020][30];
	for (int i = 0; i < 5020; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			dist[i][j] = inf;
		}	
	}
	
	dist[u][28] = 0;
	priority_queue<iii,vi, greater<iii> >q;
	q.push(iii(ii(0,28),u));
	
	while (!q.empty())
	{
		iii a = q.top();
		q.pop();
		
		for (int i = 0; i < (int)g[a.vertice].size(); i++)
		{
			iii v = g[a.vertice][i];
			
			if (v.letra != a.letra && dist[a.vertice][a.letra] + v.tamanho < dist[v.vertice][v.letra])
			{	
				dist[v.vertice][v.letra] = dist[a.vertice][a.letra] + v.tamanho;
				q.push(iii(ii(dist[v.vertice][v.letra],v.letra),v.vertice));
			}
		}		
	}
	int minimo = inf;
	for (int i = 0; i < 26; i++)
	{
		minimo = min(minimo,dist[volta][i]);
	}
	
	return minimo;
}

int main()
{
	int M,cont;
	string to,vo,cid1,cid2,palavra;
	while (scanf("%d",&M), M)
	{	
		map<string,int>m;
		cin>>to>>vo;
		cont = 1;
		for (int i = 0; i < M; i++)
		{
			cin>>cid1>>cid2;
			getchar();
			getline(cin,palavra);
			
			if (!m.count(cid1))
			{
				m[cid1] = cont;
				cont++;
			}
			
			if (!m.count(cid2))
			{
				m[cid2] = cont;
				cont++;
			}
			
			int tam = palavra.size();
			
			g[m[cid1]].push_back(iii(ii(tam,palavra[0] - 'a'),m[cid2]));
			g[m[cid2]].push_back(iii(ii(tam,palavra[0] - 'a'),m[cid1]));
		}
		
		if (m.count(to) && m.count(vo) && vo!=to)
		{	
			int resp = d(m[to],m[vo]);
			if (resp!=inf)
				printf("%d\n",resp);
			else
				puts("impossivel");
			
		}else
			puts("impossivel");
			
		for (int i = 0; i < 5020; i++)
		{
			g[i].clear();
		}	
	}
}
