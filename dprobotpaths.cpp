/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000009
int dp[1001][1001];
ll robotpaths(int ro,int col)
{
    if(dp[0][0]==-1)
    return 0;
    for(int i=0;i<col;i++)
    {
        if(dp[0][i]==-1)
        break;
        
        dp[0][i]=1;
    }
    for(int i=0;i<ro;i++)
    {
        if(dp[i][0]==-1)
        break;
        
        dp[i][0]=1;
    }
    for(int i=1;i<ro;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(dp[i][j]==-1)
            continue;
            
            dp[i][j]=0;
            if(dp[i-1][j]!=-1)
            dp[i][j]=dp[i-1][j]%mod;
            if(dp[i][j-1]!=-1)
            dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }
    if(dp[ro-1][col-1]==-1)
    return 0;
    return dp[ro-1][col-1];
}

int main()
{
    ll m,n,p;
    cin>>m>>n>>p;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<p;i++)
    {
        int x,y;
        cin>>x>>y;
        dp[x-1][y-1]=-1;
    }
    cout<<robotpaths(m,n)<<endl;

}

