#include <bits/stdc++.h>

using namespace std;
int linha[9],N,vet[9],minM;
bool lugar(int r, int c)
{
	for (int i = 1; i < c; i++)
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
	if(c == 9)
	{	
		//~ cout<<linha[vet[1]]<<" "<<vet[1]<<endl;
		int aux = 0;
		for (int j = 1; j < 9; j++)
		{
			if (vet[j] != linha[j])
			{
				aux++;
			}	
		}
		minM = min(minM,aux);
	}
	for (int r = 1; r < 9; r++)
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
	int N = 1;
	while(scanf(" %d %d %d %d %d %d %d %d",&vet[1],&vet[2],&vet[3],&vet[4],&vet[5],&vet[6],&vet[7],&vet[8])!=EOF)
	{	
		memset(linha, 0 ,sizeof linha);
		minM = 123456789;
		backtracking(1);
		printf("Case %d: %d\n",N,minM);
		N++;
	}	
	
}
