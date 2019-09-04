#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef vector<int>vi;
map<int,string>m;
map<string,int>s;
vi G[351];
string aux,caminho[351];

int bfs(int inicio, int fim)
{
	vi dist(350,inf);
	for (int i = 0; i < 350; i++)
	{
		caminho[i] = "";
	}

	dist[inicio] = 0;
	queue<int>q;
	q.push(inicio);
	caminho[inicio] = m[inicio];
	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		for (int i = 0; i < (int)G[a].size(); i++)
		{
			int v = G[a][i];
			if (dist[v] > dist[a] + 1)
			{
				dist[v] = dist[a] + 1;
				caminho[v] = caminho[a] + " " + m[v];
				q.push(v);
			}else if(dist[v] == dist[a] + 1 && (caminho[a] + " " + m[v]) < caminho[v])
			{
				caminho[v] = caminho[a] + " " + m[v];
			}
		}	
	}
	return dist[fim];
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int N,M,n,resp,aqui,la,numaux;
	char traco;
	string linha,aux;
	for (int i = 1; i <=350 ; i++)
	{
		aux = "";
		numaux = i;
		while (numaux)
		{
			aux+=((numaux%10) + '0');
			numaux/=10;	
		}
		string novoaux = "";
		for (int j = (int)aux.size() - 1; j >=0 ; j--)
		{
			novoaux += aux[j];
		}
		
		m[i] = novoaux;
		s[novoaux] = i;
	}
	

	while(scanf("%d",&N)!=EOF)
	{	puts("-----");
		for (int j = 0; j < N; j++)
		{
			scanf(" %d %c",&n,&traco);
			getline(cin,linha);
			int tam = linha.size();
			aux = "";
			for (int i = 0; i < tam; i++)
			{	
				if (linha[i] == ',')
				{
					G[n].push_back(s[aux]);
					aux = "";
				}else
				{
					aux += linha[i];
				}
			}	
			if(linha != "")
			{	
				G[n].push_back(s[aux]);
			}
		}
		scanf(" %d",&M);		

		for (int i = 0; i < M; i++)
		{
			scanf("%d%d",&aqui,&la);
			resp = bfs(aqui,la);
			if(resp == inf)
				puts("connection impossible");
			else
				cout<<caminho[la]<<"\n";
		}

		for (int i = 0; i < 350; i++)
		{
			G[i].clear();
		}
	}
}
