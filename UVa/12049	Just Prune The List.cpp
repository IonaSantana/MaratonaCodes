#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cont,t,tam1,tam2,m1,m2;
	map<int,int>s1,s2;
	map<int,int>::iterator it1,it2,aux;
	scanf("%d",&t);
	for (int j = 0; j < t; j++)
	{
		scanf("%d %d",&tam1,&tam2);
		for (int i = 0; i < tam1; i++)
		{
			scanf("%d",&m1);
			s1[m1]++;
		}
		for (int i = 0; i < tam2; i++)
		{
			scanf("%d",&m2);
			s2[m2]++;
		}
		cont = 0;
		it1 = s1.begin();
		while(it1 != s1.end())
		{
			if (s2.find(it1->first) == s2.end())
			{
				cont+= it1->second;
				aux = it1;
				it1++;
				s1.erase(aux);	
				//printf("oi\n");			
			}else
			{
				//printf("oii\n");
				cont+= abs(it1->second - s2[it1->first]);
				aux = it1;
				it1++;
				//puts("deu ruim");
				s1.erase(aux);
				s2.erase(aux->first);
			}
			//puts("SAI");
		}
		it2 = s2.begin();
		while( it2 != s2.end())
		{
			if (s1.find(it2->first) == s1.end())
			{
				//printf("oiii\n");
				cont+= it2->second;
				aux = it2;
				it2++;
				s2.erase(aux);				
			}else
			{
				//printf("oiiii\n");
				it2++;
			}
		}	
		printf("%d\n",cont);
	}
	
	
}
