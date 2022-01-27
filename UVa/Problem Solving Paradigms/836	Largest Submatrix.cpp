#include <bits/stdc++.h>

using namespace std;
int mat[50][50];

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	string s; 
	int N,t;
	long long soma,ans=0;
	scanf("%d",&t);
	for(int lm = 0; lm < t; lm++)
	{
		if(lm)
			puts("");
		soma = ans = 0;
		cin>>s;
		N = s.size();
		mat[0][0] = (s[0] - 48);
		if(!mat[0][0])
			mat[0][0] = -1000;
		for (int i = 1; i < N; i++)
		{
			mat[0][i] = (s[i] - 48);
			if(!mat[0][i])
				mat[0][i] = -1000;
			mat[0][i] += mat[0][i-1];
			
		}
		
		for (int i = 1; i < N; i++)
		{	cin>>s;
			for (int j = 0; j < N; j++)
			{
				mat[i][j] = (s[j] - 48);
				if(!mat[i][j])
					mat[i][j] = -1000;
				mat[i][j] += mat[i-1][j];
				if(j > 0)
				{ 
					mat[i][j] += mat[i][j-1];
					mat[i][j] -= mat[i-1][j-1];
				}
			}
			
		}
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = i; k < N; k++)
				{
					for (int l = j; l < N; l++)
					{
						soma = mat[k][l];
						if(i > 0) soma -= mat[i-1][l];
						if(j > 0) soma -= mat[k][j-1];
						if(i > 0 && j > 0) soma += mat[i-1][j-1];
						
						ans = max(soma,ans);
					}	
				}	
			}	
		}	
		printf("%lld\n",ans);	
	}
	
}
