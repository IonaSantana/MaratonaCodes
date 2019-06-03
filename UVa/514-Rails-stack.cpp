#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N,i, n1,a;
    stack<int>entrada;
    stack<int>estacao;
    while(scanf("%d", &N),N)
    {
        while(scanf("%d",&n1),n1)
        {  a=N;
            entrada.push(n1);
            for (i = 1; i < N; i++)
            {
                scanf("%d",&n1);
                entrada.push(n1);
            }
            while(a>0)
            {
                //printf("desgraca");
                while (!entrada.empty() && entrada.top()==a)
                {
                    a--;
                    entrada.pop();
                }
                while (!estacao.empty() && estacao.top()==a)
                {
                    a--;
                    estacao.pop();
                }
                while (!entrada.empty() && entrada.top()!=a )
                {
                    estacao.push(entrada.top());
                    entrada.pop();
                }
                if ((!entrada.empty() && !estacao.empty() && entrada.top()!=a && estacao.top()!=a) || !estacao.empty() && estacao.top()!=a && entrada.empty())
                {
                    a=0;
                }
            }
            
            if (estacao.empty() && entrada.empty())
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");

            }
            while (!estacao.empty())
            {
                estacao.pop();
            }
            while (!entrada.empty())
            {
                entrada.pop();
            }
           // a = N; // O A PRECISAVA RECEBER O VALOR DE N NOVAMENTE, PORQUE ESTÁVAMOS ZERANDO ELE TODA VEZ PARA VALIDAR AS COISAS <---
        }
        
        if (n1==0)
        {
              printf("\n");
        }
    }
}
