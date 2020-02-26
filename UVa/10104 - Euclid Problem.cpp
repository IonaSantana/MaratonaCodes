#include <bits/stdc++.h>  
using namespace std; 
  
long long gcdExtended(long long a, long long b, long long *x, long long *y)  
{  
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
    long long x1, y1; 
    long long gcd = gcdExtended(b%a, a, &x1, &y1);  
  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
}  
  
int main()  
{  
    long long x, y, a, b,g;
    
    while (scanf("%lld%lld",&a,&b)!=EOF)
	{
		g = gcdExtended(a, b, &x, &y);  
		if(a == b)
			swap(x,y);
		printf("%lld %lld %lld\n",x,y,g);
	}  
}  
