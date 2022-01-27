#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef vector<int>vi;
vi G[20000];
int cont = 1,cidade2;
map<int,string>sa;
string s[20000];

int bfs(int u)
{
	vector<int>dist(20000,inf);
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
				s[v] = s[a] + sa[a] + " " + sa[v] + "\n";
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
	
	int V,cas = 0;
	string cid1,cid2;
	while (scanf("%d",&V)!=EOF)
	{	
		if(cas)
			puts("");
		cas++;	
		map<string,int>m;
		cont = 1;
		cin.ignore();
		for (int i = 0; i < V; i++)
		{
			cin>>cid1>>cid2;
			
			if (m.find(cid1)==m.end())
			{
				sa[cont] = cid1;
				m[cid1] = cont;
				cont++;
			}
			if (m.find(cid2)==m.end())
			{
				sa[cont] = cid2;
				m[cid2] = cont;
				cont++;
			}
			
			G[m[cid1]].push_back(m[cid2]);
			G[m[cid2]].push_back(m[cid1]);
		}

		cin>>cid1>>cid2;
		if(m.find(cid2) == m.end())
		{
			puts("No route");
		}else
		{
			cidade2 = m[cid2];
			int resp = bfs(m[cid1]);
			if (resp == inf)
			{
				puts("No route");
			}else
			{
				cout<<s[cidade2];
			}	
		}
		
		for (int i = 0; i < 20000; i++)
		{
			G[i].clear();
			s[i] = "";
		}
		sa.clear();
	}
}
