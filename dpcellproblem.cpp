/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solvecells(int n,int x,int y,int z)
{
    ll *dp=new ll[n+1];
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            dp[i]=min(dp[i/2]+x, dp[i-1]+y);
        }
        else
        {
            dp[i]=min(dp[(i+1)/2]+x+z,dp[i-1]+y);
        }
    }
    return dp[n];
}

int main()
{
    ll n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<solvecells(n,x,y,z)<<endl;
    return 0;
}

