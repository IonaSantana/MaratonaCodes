#include <bits/stdc++.h>

using namespace std;
#define inf 0x3f3f3f3f
int dist[110][110];

int main()
{
  int divide,qts,v,a,v1,a1,maximo,i=1;
  while(scanf("%d%d",&v,&a), v || a)
  { 
    for(int i = 0; i < 110; i++)
    {
      for(int j = 0; j < 110; j++)
      {
        dist[i][j] = inf;
      }
    }
    maximo = max(v,a);
    dist[v][a] = 1;
    while(scanf("%d%d",&v1,&a1), v1 || a1)
    {
      maximo = max(v1,maximo);
      maximo = max(a1,maximo);
      dist[v1][a1] = 1;
    }
    for (int i = 1; i <= maximo; i++)
    {
        dist[i][i]= 0;
    }
    qts = divide = 0;
    for(int k = 1; k <= maximo; k++)
    {
      for(int i = 1; i <= maximo; i++)
      {
        for(int j = 1; j <= maximo; j++)
        {
          dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
        }
      } 
    }
    for(int i = 1; i <= maximo; i++)
    {
      for(int j = 1; j <= maximo; j++)
      {
        if(dist[i][j]!=inf)
        {
          divide++;
          qts+=dist[i][j];
        }
      }
    } 
    printf("Case %d: average length between pages = %.3lf clicks\n",i,qts/((double)divide-maximo));
    i++;
  }
}
