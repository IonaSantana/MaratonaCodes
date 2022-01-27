#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>ii;
typedef vector<ii>vi;
int t,w,n;
long long pd[35][1000000];
int valor[35],peso[35];
vi caminho;
long long mochila(int item, int disp)
{
	if(disp == 0 || item == n) return 0;
	if(pd[item][disp]!=-1) return pd[item][disp];
	
	if(disp - (3*w*peso[item]) < 0)
	{
		pd[item][disp] = mochila(item+1,disp);
	}else
	{	
		pd[item][disp] = max(mochila(item+1,disp),valor[item] + mochila(item+1, disp - (3*w*peso[item])));
	}
	
	return pd[item][disp];
}
void mochilaCaminhoSemRepeticao(int item, int Disp)
{
	if(Disp==0 || item == n)return;
	
	if(Disp - (3*w*peso[item]) < 0)
	{
		 mochilaCaminhoSemRepeticao(item+1,Disp);
	}else
	{	
		if (valor[item] + mochila(item+1,Disp-(3*w*peso[item])) > mochila(item+1,Disp))
		{
			caminho.push_back(ii(peso[item],valor[item]));
			mochilaCaminhoSemRepeticao(item+1,Disp-(3*w*peso[item]));
			return;
		}else
		{
			mochilaCaminhoSemRepeticao(item+1,Disp);
		}			
	}	 	
}
int main()
{
	int a,j=0;
	while (scanf("%d%d",&t,&w)!=EOF)
	{	
		if (j>0)printf("\n");
		j++;		
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d",&peso[i],&valor[i]);
		}
		memset(pd,-1,sizeof pd);
		caminho.clear();
		printf("%lld\n",mochila(0,t));
		mochilaCaminhoSemRepeticao(0,t);
		a = caminho.size();
		printf("%d\n",a);
		for (int i = 0; i < a; i++)
		{
			printf("%d %d\n",caminho[i].first,caminho[i].second);
		}				
	}
}





