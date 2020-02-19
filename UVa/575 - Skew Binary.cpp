#include <bits/stdc++.h>

using namespace std;

int main()
{
	string muitao;
	int tamanho;
	long long numero;
	while (cin>>muitao, muitao[0]!= '0')
	{
		tamanho = muitao.size();
		numero = 0;
		for (int i = 0; i < tamanho; i++)
		{
			numero += (pow(2,tamanho-i) - 1) * (muitao[i]-48);
		}
		cout<<numero<<"\n";	
	}
}
