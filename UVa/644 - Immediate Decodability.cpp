#include<bits/stdc++.h>
using namespace std;

#define maxc 1030

int trie[maxc][2];
bool fim[maxc];
int cntV;
bool resp;
void inserir(string str){
	int x = 0;
	int tam = (str.size()-1);
	for (int i = 0; str[i]; i++)
	{
		int prox = trie[x][str[i]-48];
		if (prox == 0){
			trie[x][str[i]-48] = ++cntV;
			prox = cntV;
		}else if(fim[prox] || i==tam )
		{
			//~ cout<<"prox"<<prox<<endl;
			resp =1;
		}		
		x = prox;
	}
	fim[x] = 1;
}

int main (){
	
	//~ freopen("in","r",stdin);
	int i=1,tam=0;
	char S[11];
	vector<string>palavras;
	
	while(scanf("%s",S)!=EOF)
	{
		if(S[0]=='9')
		{	
			memset(trie,0,sizeof trie);
			memset(fim,0,sizeof fim);
			resp = 0;
			cntV = 0;
			tam = palavras.size();
			for (int j = 0; j < tam; j++)
			{
				inserir(palavras[j]);
			}
			if (!resp)
				printf("Set %d is immediately decodable\n",i);
			else
				printf("Set %d is not immediately decodable\n",i);				
			i++;		
			palavras.clear();
		}else
		{
			palavras.push_back(S);		
		}	
	}
	
	
}

