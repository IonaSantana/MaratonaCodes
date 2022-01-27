#include <bits/stdc++.h>

using namespace std;
int linha[9],N,vet[9],maxM,matriz[9][9];
bool lugar(int r, int c)
{
	for (int i = 0; i < c; i++)
	{
		if (linha[i] == r || (abs(linha[i] - r) == abs(i - c)))
		{
			return false;
		}
	}
	return true;
}
void backtracking(int c)
{
	if(c == 8)
	{	
		//~ cout<<linha[vet[1]]<<" "<<vet[1]<<endl;
		int aux = 0;
		for (int j = 0; j < 8; j++)
		{
			aux += matriz[linha[j]][j];
		}
		maxM = max(maxM,aux);
	}
	for (int r = 0; r < 8; r++)
	{
		if (lugar(r,c)) 
		{
			linha[c] = r;
			backtracking(c + 1);
		}
		
	}
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int N;
	scanf("%d",&N);
	while(N--)
	{	
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				scanf("%d",&matriz[i][j]);
			}			
		}	
		
		memset(linha, 0 ,sizeof linha);
		maxM = 0;
		backtracking(0);
		printf("%5d\n",maxM);
	}	
	
}


