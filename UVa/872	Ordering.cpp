#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
typedef vector<string>vs;
vs resposta;
vi g[30],res;
bool visitado[30];
int incidencia[30],cont;
map<char,int>ci;
map<int,char>ic;

void printTopological()
{
	bool flag = 0;
	for (int j = 1; j < cont ; j++)
	{	
		if (!incidencia[j] && !visitado[j])
		{
			for (int i = 0; i <(int)g[j].size() ; i++)
				incidencia[g[j][i]]--;
			res.push_back(j);
			visitado[j] = 1;
			printTopological();
		
			visitado[j] = 0;
		
			res.erase(res.end() - 1);
			for (int i = 0; i <(int)g[j].size() ; i++)
				incidencia[g[j][i]]++;
			flag = 1;
		}			
	}
	
	if (!flag)
	{	
		string gera = "";
		int tam = res.size();
		if(tam)
		{
			gera = ic[res[0]];
			
			for (int i = 1; i < tam; i++)
			{
				gera = gera + " " + ic[res[i]];
			}
			resposta.push_back(gera);
		}	
	}
}
int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	string frase,texto;
	int T;
	scanf("%d ",&T);
	for(int j = 0; j < T; j++)
	{	
		if(j)
			puts("");
		cont = 1;
		
		getline(cin,frase);
		int tam = frase.size();
		for (int i = 0; i < tam; i+=2)
		{
			ci[frase[i]] = cont;
			ic[cont] = frase[i];
			cont++;
		}
		getline(cin,texto);
		tam = texto.size();
		for (int i = 0; i < tam; i+=4)
		{
			g[ci[texto[i]]].push_back(ci[texto[i+2]]);
			incidencia[ci[texto[i+2]]]++;
		}
		printTopological();
		tam = resposta.size();
		if(tam)
		{
			sort(resposta.begin(), resposta.end());
			for (int i = 0; i < tam; i++)
			{
				cout<<resposta[i]<<"\n";
			}
		}
		else
			puts("NO");
		for (int i = 0; i < 30; i++)
		{
			incidencia[i] = 0;
			visitado[i] = 0;
			g[i].clear();
		}
		res.clear();
		ic.clear();
		ci.clear();
		resposta.clear();
		getchar();
	}
	
}
