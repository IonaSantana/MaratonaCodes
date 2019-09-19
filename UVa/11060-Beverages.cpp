#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int N,M,contador = 1;
	string bebida,lig1,lig2;
	while (scanf("%d",&N)!=EOF)
	{
		map<string,int>si;
		map<int,string>is;
		vi g[210],top_order,entrada(210,0);
		for (int i = N; i > 0; i--)
		{
			cin>>bebida;
			si[bebida] = i;
			is[i] = bebida;
		}

		scanf(" %d",&M);
		for (int i = 0; i < M; i++)
		{
			cin>>lig1>>lig2;
			g[si[lig1]].push_back(si[lig2]);
		}
		
		for (int i = N; i > 0; i--)
		{
			for (int j = 0; j < (int)g[i].size(); j++)
			{
				entrada[g[i][j]]++;
			}
		}
		
		priority_queue<int>q;
		for (int i = 1; i <= N; i++)
		{
			if(entrada[i] == 0)
				q.push(i);
		}

		while (!q.empty())
		{
			int u = q.top();
			q.pop();
			top_order.push_back(u);
			for (int i = 0; i < (int)g[u].size(); i++)
			{
				if ((--entrada[g[u][i]]) == 0)
					q.push(g[u][i]);
			}
		}
		int tam = top_order.size();
		cout<<"Case #"<<contador<<": Dilbert should drink beverages in this order:";
		for (int i = 0; i < tam; i++)
		{
			cout<<" "<<is[top_order[i]];
		}
		puts(".\n");
		getchar();
		contador++;
	}
}
