#include <bits/stdc++.h>

using namespace std;
int N,t;
vector<int>cd;
vector<int>caminho;
int backtracking(int item,int soma)
{
	//if(soma == N) return 1;
	if(item == t || soma == 0) return 0;
	
	if(soma - cd[item] >= 0)
		return max(cd[item] + backtracking(item+1,soma - cd[item]),backtracking(item+1,soma)); 
	return backtracking(item+1,soma);
}
void reconstrucao(int item,int soma)
{
	//if(soma == N) return;
	if(item == t || soma == 0) return;
	
	if(soma - cd[item] >= 0)
	{
		if ((cd[item] + backtracking(item+1,soma - cd[item])) > backtracking(item+1,soma))
		{
			caminho.push_back(cd[item]);
			reconstrucao(item+1,soma - cd[item]);
			return;
		}
	}
	reconstrucao(item+1,soma);	
}

int main()
{
	int col,i,soma=0;
	while(scanf("%d",&N)!=EOF)
	{
		scanf("%d",&t);
		for (i = 0; i < t; i++)
		{
			scanf("%d",&col);
			cd.push_back(col);
		}
		soma = 0;
		reconstrucao(0,N);
		for (i = 0; i < (int)caminho.size(); i++)
		{
			cout<<caminho[i]<<" ";
			soma += caminho[i];
		}
		
		cout<<"sum:"<<soma<<"\n";
		caminho.clear();
		cd.clear();
	}
}
