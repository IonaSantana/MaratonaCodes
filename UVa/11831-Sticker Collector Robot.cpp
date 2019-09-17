#include <bits/stdc++.h>

using namespace std;
string instrucoes;
char matriz[110][110];
int stickers, inl, inc,N,M,S,sizinho,x[] = {-1,0,1,0}, y[] = {0,1,0,-1};
map<char,int>m;

void dfs(int l, int c, int rumo)
{
	for (int i = 0; i < sizinho; i++)
	{
		if (instrucoes[i] == 'F')
		{
			int a = l + x[rumo];
			int b = c + y[rumo];
			
			if(a >= 0 && a < N && b >= 0 && b < M && matriz[a][b] != '#')
			{
				l = a;
				c = b;
				if (matriz[l][c] == '*')
				{
					stickers++;
					matriz[l][c] = '.';
				}
			}
		}else if(instrucoes[i] == 'E')
		{
			rumo = (4 + rumo - 1)%4;
		}else
		{
			rumo = (rumo + 1)%4;
		}
	}
}

int main()
{
	char *pega,comeca;
	m['N'] = 0;
	m['L'] = 1;
	m['S'] = 2;
	m['O'] = 3;
	
	while (scanf("%d%d%d",&N,&M,&S), N || M || S)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf(" %c",&matriz[i][j]);
				pega = &matriz[i][j];
				if(*pega != '.' && *pega != '*' && *pega != '#')
				{
					inl = i;
					inc = j;
					comeca = *pega;
				}	
			}
		}
		
		cin>>instrucoes;
		sizinho = instrucoes.size();
		stickers = 0;
		dfs(inl,inc,m[comeca]);
		printf("%d\n",stickers);
	}

}
