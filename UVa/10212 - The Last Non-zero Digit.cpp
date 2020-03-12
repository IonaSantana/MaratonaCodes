#include <bits/stdc++.h>
using namespace std;
#define mod 10000000000
int main()
{
    unsigned long long n,m,resp,c,i;

    while (scanf("%llu%llu",&n,&m)!=EOF)
    {
        resp = 1;
        c = n-m+1;
        for (i = n; i >= c; i--)
        {
            resp = (resp*i);
            while (resp%10 == 0)
                resp /= 10;
            resp = resp%mod;
        }
        printf("%llu\n",resp%10);
    }
}
