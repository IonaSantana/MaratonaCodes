#include <bits/stdc++.h>

using namespace std;

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	int n,t;
	string frase,frase1;
	map<string,string>m;
	scanf(" %d",&n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin,frase);
		getline(cin,frase1);
		m[frase] = frase1;
	}

	scanf(" %d",&t);
	getchar();
	for (int i = 0; i < t; i++)
	{
		getline(cin,frase);
		cout<<m[frase]<<"\n";
	}
}
