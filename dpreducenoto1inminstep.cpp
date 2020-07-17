/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
long long int a[10000];
long long int reduceno(int n)
{
    if(n==1) return 0;
    int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
    if(a[n]!=-1) return a[n];
    if(n%3==0) q1=1+reduceno(n/3);
    if(n%2==0) q2=1+reduceno(n/2);
    q3=1+reduceno(n-1);
    a[n]=min(q1,min(q2,q3));
    return a[n];
}
long long int reduceno_usingbottomup(int n)
{
    int dp[10000];
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int curnum=4;curnum<=n;curnum++)
    {
        int q1=INT_MAX;
        int q2=INT_MAX;
        int q3=INT_MAX;
        if(curnum%3==0) q1=1+dp[curnum/3];
        if(curnum%2==0) q2=1+dp[curnum/2];
        q3=1+dp[curnum-1];
        dp[curnum]=min(q1,min(q2,q3));
    }
    return dp[n];
    
}
int main()
{
    int n;
    cin>>n;
    for(long long int i=0;i<10000;i++)
    {
        a[i]=-1;
    }
    long long int ans=reduceno_usingbottomup(n);
    
    cout<<ans<<endl;

    return 0;
}

