#include <bits/stdc++.h>

using namespace std;
string aux,key,leitura;
void ler(map<string,string>&m)
{
	aux = "";	
	key = "";
	int s = leitura.size() - 1;
	for(int i = 1; i < s; i++)
	{		
		if(leitura[i] == ':')
		{
			m[aux] = "";
			key = aux;
			//cout<<aux<<endl;
			aux = "";
		}else if(leitura[i] == ',')
		{
			m[key] = aux;
			key = "";
			aux = "";			
		}else
		{
			aux += leitura[i];
		}
	}
	m[key] = aux;
	aux = "";

}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	map<string,string> m;
	map<string,string> m1;	
	map<string,string>::iterator it;
	
	int n;
	
	scanf("%d",&n);
	getchar();
	for (int j = 0; j < n; j++)
	{
		vector<string>mais;
		vector<string>menos;
		vector<string>continua;
		
		cin>>leitura;		
		ler(m);
		
		cin>>leitura;	
		ler(m1);
		
		m.erase("");
		m1.erase("");

		for (it = m.begin(); it != m.end(); it++)
		{
			if(m1.find(it->first) != m1.end())
			{
				if(it->second != m1[it->first])
					continua.push_back(it->first);
			
			}else
			{
				menos.push_back(it->first);
			}
		}
		for (it = m1.begin(); it != m1.end(); it++)
		{
			if(m.find(it->first) == m.end())
			{
				mais.push_back(it->first);			
			}
		}
		int tam = mais.size(),tam1 = continua.size(), tam2 = menos.size();
		if(tam == 0 && tam1 == 0 && tam2 == 0)
		{
			puts("No changes\n");
		}
		else
		{
			if(tam)
			{
				printf("+");
				for (int i = 0; i < tam-1; i++)
				{
					cout<<mais[i]<<",";
				} 
				cout<<mais[tam-1]<<endl;
			}
			if(tam2)
			{
				printf("-");
				for (int i = 0; i < tam2-1; i++)
				{
					cout<<menos[i]<<",";
				} 
				cout<<menos[tam2-1]<<endl;
			}
			
			if(tam1)
			{
				printf("*");
				for (int i = 0; i < tam1-1; i++)
				{
					cout<<continua[i]<<",";
				} 
				cout<<continua[tam1-1]<<endl;
			}
			printf("\n");
		}
	    m.clear();		
		m1.clear();

	}
}
