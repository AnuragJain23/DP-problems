
#include <bits/stdc++.h>
using namespace std;
int a[10000];
int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(a[n]!=-1) return a[n];
    
    int ans=fib(n-1)+fib(n-2);
    a[n]=ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<10000;i++)
    {
        a[i]=-1;
    }
    int ans=fib(n);
    
    cout<<ans<<endl;

    return 0;
}

