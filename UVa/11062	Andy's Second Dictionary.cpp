#include <bits/stdc++.h>
using namespace std;

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	string linha,palavra = "";
	int s;
	set<string>m;
	set<string>::iterator it;
	while(getline(cin,linha))
	{
		s = linha.size();
		for (int i = 0; i < s-1; i++)
		{
			if((linha[i] < 65 || (linha[i] > 90 && linha[i] < 97) || linha[i] > 122) && linha[i]!= '-')
			{
				m.insert(palavra);
				//~ cout<<palavra<<endl;
				palavra = "";
			}else if(linha[i] < 97 && linha[i] != '-')
			{
				palavra += linha[i] + 32;
			}else
			{
				palavra += linha[i];
			}
		}
		if(linha[s-1] >= 97 && linha[s-1] <= 122)
		{
			palavra += linha[s-1];
			//~ cout<<palavra<<endl;
			m.insert(palavra);
			palavra = "";
			
		}else if(linha[s-1] >= 65 && linha[s-1] <= 90)
		{
			palavra += (linha[s-1] + 32);
			//~ cout<<palavra<<endl;
			m.insert(palavra);
			palavra = "";
		}else if(linha[s-1] != '-')
		{
			//~ cout<<palavra<<endl;
			m.insert(palavra);
			palavra = "";
		}
	}
	m.erase("");
	for (it = m.begin(); it != m.end(); it++)
	{
		cout<<*it<<"\n";
	}
	
}
