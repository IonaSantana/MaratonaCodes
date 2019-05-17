#include <bits/stdc++.h>

using namespace std;
int linha[8],N,a,b, linhaCount;
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
	if(c == 8 && linha[b] == a)
	{
		printf("%2d      %d",++linhaCount, linha[0] + 1);
		for (int j = 1; j < 8; j++)
		{
			printf(" %d",linha[j] + 1);
		}
		printf("\n");
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
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d",&a,&b);
		a--;
		b--;
		
		memset(linha, 0 ,sizeof linha);
		linhaCount = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtracking(0);
		if(i < N-1)
			printf("\n");
	}	
	
}
