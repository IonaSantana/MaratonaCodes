#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef vector<int>vi;
vi G[210];

int resp;

int bfs(int u)
{
	vector<int>dist(210,inf);
	
	dist[u] = 0;
	queue<int>q;
	q.push(u);
	
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		
		for (int i = 0; i < (int)G[a].size(); i++)
		{
			int v = G[a][i];
			if (dist[v] == inf)
			{
				dist[v] = dist[a] + 1;
				q.push(v);
			}
		}	
	}

	return dist[resp];
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	string s,s1,s2,barran;
	int cont,N;

	scanf("%d",&N);
	cin.ignore();
	for (int j = 0; j < N; j++)
	{
		map<string,int>m;
		map<int,string>s3;
		map<string,int>::iterator it;
		if(j)
			puts("");
		cont = 1;
		while (cin>>s, s!="*")
		{
			s3[cont] = s;
			m[s] = cont;
			cont++;

		}
		
		for (it = m.begin(); it!= m.end(); it++)
		{
			string aux = it->first;
			int tam = aux.size();
			for (int i = 0; i < tam; i++)
			{
				aux = it->first;
				for (int k = 0; k < 26; k++)
				{
					aux[i] = 'a' + k;
					if (m.find(aux) != m.end() && aux != it->first)
					{ 
						G[it->second].push_back(m[aux]);
					}
				}		
			}	
		}		

		cin.ignore();
		while (getline(cin,barran) && barran.size() > 0)
		{
			s1 = s2 = "";
			int tamanho = barran.size(),peguei;
			for (int i = 0; i < tamanho; i++)
			{
				if (barran[i] == ' ')
				{
					peguei = i;
					break;
				}
				s1 += barran[i];
			}		
			for (int i = peguei+1; i < tamanho; i++)
				s2 += barran[i];
	
			resp = m[s2];
			cout<<s1<<" "<<s2<<" "<<bfs(m[s1])<<"\n";
		}
		
		for (int i = 0; i < 210; i++)
		{
			G[i].clear();
		}
	}
}
