#include <bits/stdc++.h>

using namespace std;
int main()
{
   //~ freopen("in","r",stdin);
   //~ freopen("out","w",stdout);
   string a,aux;
   set<string>andy;	 	
   set<string>::iterator it;	 	
   while (getline(cin,a))
   {
	   int s = a.size();
	   aux = "";
	   for (int i = 0; i < s; i++)
	   {
		   if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		   {
			   aux += tolower(a[i]);
		   }else
		   {
			   andy.insert(aux);
			   aux = "";
		   }		   
	   }
	   andy.insert(aux);
   }
   if(andy.find("") != andy.end())
		andy.erase("");
		
   for (it = andy.begin(); it != andy.end() ; it++)
   {
	   cout<<*it<<"\n";
   }
   
}
