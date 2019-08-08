#include <bits/stdc++.h>

using namespace std;

int main()
{
	//~ freopen("in5","r",stdin);
	//~ freopen("out5","w",stdout);
	map<string,set<string> >projetos;
	map<string,set<string> >::iterator it;
	set<string>s,jatem;
	set<string>::iterator its;
	string p,proj;
	
	while(getline(cin,proj), proj != "0")
	{
		if( proj[0] == '1')
		{
			map<string,int>r;
			vector<string>resp;
			projetos[p];
			resp.push_back("-1");
			r["-1"] = 0;
			for(it = projetos.begin(); it!= projetos.end(); it++)
			{
				int tam = (it->second).size();
				for(its = jatem.begin(); its != jatem.end(); its++)
				{			
					if(projetos[it->first].find(*its) != projetos[it->first].end())
					{
						tam--;
					}
				}
				int i = 0;
				int tamanho = resp.size();
				while (i < tamanho && tam <= r[resp[i]])
				{
					i++;
				}
				r[it->first] = tam;
				resp.insert(resp.begin() + i, it->first);		
			}

			int tamanho = resp.size();
			for (int i = 0; i < tamanho; i++)
			{
				if(resp[i] != "-1")
					cout<<resp[i]<<" "<<r[resp[i]]<<"\n";
			}
				
			projetos.clear();
			jatem.clear();
			s.clear();
			
		}else if(proj[0] < 96)
		{
			p = proj;
			projetos[p];

		}else
		{
					
			if(s.find(proj) != s.end())
			{
				if(projetos[p].find(proj) == projetos[p].end())
					jatem.insert(proj);
			}
			projetos[p].insert(proj);
			s.insert(proj);
		}
	}
}


