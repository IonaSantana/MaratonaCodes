#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define DFS_WHITE -1
#define DFS_BLACK 1
map<int,int>vertices;
vector<vii> G;
vi dfs_num;
vi dfs_parent;
vi dfs_low;
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

bool ordena(ii a, ii b)
{
	if(a.second > b.second)
	   return 1;
	if(a.second == b.second && b.first > a.first)
	   return 1;
	return 0;	
}
void articulationPointAndBridge(int u) 
{
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for(int j=0; j<(int)G[u].size(); j++) 
  {
    ii v = G[u][j];
    if(dfs_num[v.first] == DFS_WHITE) 
    {
      dfs_parent[v.first] = u;
      if(u == dfsRoot)
	rootChildren++;

      articulationPointAndBridge(v.first);

      if(dfs_low[v.first] >= dfs_num[u])
      {
        articulation_vertex[u] = true;
        vertices[u]++;
      }
	
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
      
    } else if(v.first != dfs_parent[u])
	dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
  }
}

int main() {
  int v, e;
  while(scanf("%d %d", &v, &e), v || e)
  {
	  vii vet;
	  G.assign(v, vii());
	  int a, b;
	  while(scanf("%d %d", &a, &b), a!=-1 || b!=-1)
	  {
		G[a].push_back(ii(b, 1));
	  	G[b].push_back(ii(a, 1));
	  }

	  dfsNumberCounter = 0;
	  dfs_num.assign(v, DFS_WHITE);
	  dfs_low.assign(v, 0);
	  dfs_parent.assign(v, 0);
	  articulation_vertex.assign(v, 0);
	  for(int i=0; i < v; i++) 
	  {
	      if(dfs_num[i] == DFS_WHITE) 
	      {
		dfsRoot = i;
		rootChildren = 0;
		articulationPointAndBridge(i);
		articulation_vertex[dfsRoot] = (rootChildren > 1);
	      }
	  }    

	  for(int i=0; i<v; i++) 
	  {
	      if(articulation_vertex[i])
	      {
		vet.push_back(ii(i,vertices[i]+1));

	      }else
	      {
		vet.push_back(ii(i,1));
	      }
	  }
	  sort(vet.begin(),vet.end(),ordena);
	  for (int i = 0; i < e; i++)
	  {
	      printf("%d %d\n",vet[i].first,vet[i].second);
	  }
	  puts("");
	  vertices.clear();
  }
  return 0;
}
