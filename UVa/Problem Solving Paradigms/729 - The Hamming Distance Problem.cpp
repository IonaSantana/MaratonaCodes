#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>

using namespace std;
vector<int>s;
set<string>lista;
void hamming(string bin, int n)
{   
    lista.insert(bin);
    for (int i = 0; i < n; i++)
    {
      if(s[i] - 1 >= 0 && bin[s[i]-1] == '0') 
      {
        bin[s[i]] = '0';
        bin[s[i]-1] = '1';
        s[i]=s[i]-1;
        hamming(bin,n);
        s[i]=s[i]+1;        
      }
    } 
}

int main()
{
    int t,n,h;
    set<string>::iterator it;
    scanf(" %d",&t);

    for (int i = 0; i < t; i++)
    {
        if(i)
            cout<<endl;
        scanf(" %d%d",&n,&h);

        string num;
        for(int j = 0; j < n-h; j++)
            num = num + '0';

        for(int j = n-h; j < n; j++)
        {
           num = num + '1';
           s.push_back(j);
        }
        hamming(num, s.size());   

        for(it=lista.begin(); it!=lista.end(); it++)
        {
          cout<<*it<<endl;
        }
        lista.clear();
        s.clear();
    }
}