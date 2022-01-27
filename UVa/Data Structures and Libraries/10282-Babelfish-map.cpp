#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    map <string,string> message;
    string m,aux,aux1;
    bool espaco;
    while (getline(cin,m))
    {
        int s = m.size();
        aux = "";
        espaco = 0;
        for (int i = 0; i < s; i++)
        {
            if(m[i] == ' ')
            {
                aux1 = aux;
                aux = "";
                espaco = 1;
            }else
            {
                aux += m[i];
            }				
        }
        if(espaco)
            message[aux] = aux1;
        else if(message.count(aux))
            cout<<message[aux]<<"\n";
        else if(m != "\0")
            cout<<"eh\n";
    }	
}	


