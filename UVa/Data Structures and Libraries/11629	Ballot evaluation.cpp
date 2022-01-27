#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n,m,flag;
	long double d,valor;
	string frase,expressao,aux;
	map<string , long double> ma;

	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++)
	{
		getchar();
		cin>>frase;
		scanf(" %Lf",&d);
		ma[frase] = d;	
	}
	getchar();
	for (int j = 1; j <= m; j++)
	{
		valor = 0;
		aux = "";
		getline(cin,expressao);
		int tam = expressao.size();
		for (int i = 0; i < tam; i++)
		{
			if(expressao[i] == ' ')
			{
				if(aux == ">")
				{
					flag = 1;
				}else if(aux == "<")
				{
					flag = 2;
				}else if(aux == "<=")
				{
					flag = 3;
				}else if(aux == ">=")
				{
					flag = 4;
				}else if(aux == "=")
				{
					flag = 5;
				}
				else if(aux != "+")
				{
					//cout<<i<<endl;
					//cout<<"string "<<aux<<endl;
					valor+= ma[aux];
					//cout<<valor<<endl;
				}
				aux = "";
			}else
			{
				aux += expressao[i];
			}
		}
		double a = atof(aux.c_str());
		//cout<<valor<<endl;
		
		if(flag == 1)
		{
			if((double)valor - (double)a > 0.001)
			{
				printf("Guess #%d was correct.",j);
			}else
			{
				printf("Guess #%d was incorrect.",j);
			}
		}
		else if(flag == 2)
		{
			if((double)valor - (double)a < (-1)*0.001)
			{
				printf("Guess #%d was correct.",j);
			}else
			{
				printf("Guess #%d was incorrect.",j);
			}
		}
		else if(flag == 3)
		{
			if((double)valor <= (double)a)
			{
				printf("Guess #%d was correct.",j);
			}else
			{
				printf("Guess #%d was incorrect.",j);
			}
		}
		else if(flag == 4)
		{
			if((double)valor >= (double)a)
			{
				printf("Guess #%d was correct.",j);
			}else
			{
				printf("Guess #%d was incorrect.",j);
			}
		}
		else if(flag == 5)
		{
			if(abs((double)valor - (double)a)  < 0.0001)
			{
				printf("Guess #%d was correct.",j);
			}else
			{
				printf("Guess #%d was incorrect.",j);
			}
		}
		printf("\n");
	}
	
}
