#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef vector<int>vi;
vi G[30];
int cont = 1,cidade2;
map<int,string>sa;
string s[30];

int bfs(int u)
{
	vector<int>dist(30,inf);
	dist[u] = 0;
	queue<int>q;
	q.push(u);
	s[u] = sa[u];
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
				s[v] = s[a] + sa[v];
				q.push(v);
			}
		}	
	}
	return dist[cidade2];
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	int V,T,Q;
	string cid1,cid2;
	scanf("%d",&T);
	for(int j = 0; j < T; j++)
	{	
		scanf("%d%d",&V,&Q);
		if(j)
			puts("");
		map<string,int>m;
		cont = 1;
		cin.ignore();
		for (int i = 0; i < V; i++)
		{
			cin>>cid1>>cid2;
			
			if (m.find(cid1)==m.end())
			{
				sa[cont] = cid1[0];
				m[cid1] = cont;
				cont++;
			}
			if (m.find(cid2)==m.end())
			{
				sa[cont] = cid2[0];
				m[cid2] = cont;
				cont++;
			}
			
			G[m[cid1]].push_back(m[cid2]);
			G[m[cid2]].push_back(m[cid1]);
		}
		for (int i = 0; i < Q; i++)
		{
			for (int k = 0; k < 30; k++)
			{
				s[k] = "";
			}
			cin>>cid1>>cid2;
			cidade2 = m[cid2];
			bfs(m[cid1]);
			cout<<s[cidade2]<<"\n";
		}
	
		for (int i = 0; i < 30; i++)
		{
			G[i].clear();
		}
		sa.clear();
	}
}
