#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef vector<int>vi;

vi adjlist[260];
int pai[260],res[260][260];

bool bfs(int s, int t)
{
	memset(pai,-1,sizeof pai);
	queue<int>q;
	pai[s] = s;
	
	q.push(s);
	
	while (!q.empty())
	{
		int u = q.front();	
		q.pop();
		
		for (int i = 0; i < (int)adjlist[u].size(); i++)
		{
			int v = adjlist[u][i];
			if (pai[v] == -1 && res[u][v] > 0)
			{
				pai[v] = u;
				q.push(v);
			}	
		}	
	}
	return (pai[t]!= -1);
}

int maxFlow(int s,int t)
{
	int flow = 0, gargalo,vAtual;

	while (bfs(s,t))
	{
		//break;
		gargalo = inf;
		
		vAtual = t;
		while (vAtual != s)
		{
			gargalo = min(gargalo, res[pai[vAtual]][vAtual]);		
			vAtual = pai[vAtual]; 
		}
		
		flow += gargalo;
		
		vAtual = t;
		while (vAtual != s)
		{
			res[pai[vAtual]][vAtual] -= gargalo;
			res[vAtual][pai[vAtual]] += gargalo;		
			vAtual = pai[vAtual]; 
		}
		//break;	
	}
	return flow;
}

int main()
{
	int n,soma = 0;
	string nums;
	bool flag;
	
	while (getline(cin,nums))
	{
		
		if(nums == "")
		{
			if (maxFlow(0,250) == soma)
			{
				for (int i = '0'; i <= '9'; i++)
				{	flag = 0;
					for (int j = 'A'; j <= 'Z'; j++)
					{
						if (res[i][j] == 1)
						{
							printf("%c",(char)j);
							flag = 1;
						}
						
					}
					if(!flag)
						printf("_");
				}
				puts("");
				
			}else
			{
				puts("!");
			}
			memset(res,0,sizeof res);
			for (int i = 0; i < 260; i++)
			{
				adjlist[260].clear();
			}	
			soma = 0;
		}else
		{
			n = nums[1] - 48;
			soma += n;
			adjlist[0].push_back((int)nums[0]);
			adjlist[(int)nums[0]].push_back(0);
			res[0][(int)nums[0]] = n;
			
			int tam = nums.size() - 1;
			for (int i = 3; i < tam; i++)
			{
				adjlist[(int)nums[0]].push_back((int)nums[i]);
				adjlist[(int)nums[i]].push_back((int)nums[0]);
				res[(int)nums[0]][(int)nums[i]] = 1;
			}				
			for (int i = '0'; i <= '9'; i++)
			{
				adjlist[i].push_back(250);
				adjlist[250].push_back(i);
				res[i][250] = 1;
			}					
		}		
	}	
	if (maxFlow(0,250) == soma)
	{
		for (int i = '0'; i <= '9'; i++)
		{	flag = 0;
			for (int j = 'A'; j <= 'Z'; j++)
			{
				if (res[i][j] == 1)
				{
					printf("%c",(char)j);
					flag = 1;
				}
				
			}
			if(!flag)
				printf("_");
		}
		puts("");
		
	}else
	{
		puts("!");
	}
}
