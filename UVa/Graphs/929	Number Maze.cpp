#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
int l,c,dist[1010][1010],x[] = {-1,0,1,0},y[] = {0,1,0,-1},mat[1010][1010];
typedef pair< int, int> ii;
typedef pair< int,ii > iii;
typedef vector< iii > viii;

int dis()
{
	// col*l + c
	for (int i = 0; i < 1010; i++)
	{
		for (int j = 0; j < 1010; j++)
		{
			dist[i][j] = inf;
		}	
	}
	
	priority_queue <iii,viii, greater<iii> >q;
	dist[0][0] = mat[0][0];
	q.push(iii(dist[0][0], ii(0,0)));
	
	while (!q.empty())
	{
		iii v = q.top();
		q.pop();
		
		int l1 = v.second.first,c1 = v.second.second;
		
		for (int i = 0; i < 4; i++)
		{
			int v1 = l1 + x[i];
			int v2 = c1 + y[i];
			
			if ((v1 >= 0 && v1 < l) && (v2 >= 0 && v2 < c))
			{
				if (dist[v1][v2] > dist[l1][c1] + mat[v1][v2])
				{
					dist[v1][v2] = dist[l1][c1] + mat[v1][v2];
					q.push(iii(dist[v1][v2],ii(v1,v2)));
				}	
			}
		}	
	}
	return dist[l-1][c-1];

}

int main()
{
	int n;
	scanf("%d",&n);
	
	for (int j = 0; j < n; j++)
	{
		scanf("%d%d",&l,&c);
		
		for (int i = 0; i < l; i++)
		{
			for (int k = 0; k < c; k++)
			{
				scanf("%d",&mat[i][k]);
			}	
		}
		printf("%d\n",dis());		
	}
	
}
