#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long 
#define F(i,a,b) for(ll i=a;i<=b;i++)
ll dp[2002][2002][6],n,m;
ll a[2005],b[2005];
ll korderlcs(ll i , ll j , ll k)
{
    if(i>=n||j>=m)
    return 0;
    if(dp[i][j][k]!=-1)
    return dp[i][j][k];
    ll res=0;
    if(a[i]==b[j])
    res=1+korderlcs(i+1,j+1,k);
    else
    {
        if(k>0) 
        res=1+korderlcs(i+1,j+1,k-1);
        res=max(res,korderlcs(i+1,j,k));
        res=max(res,korderlcs(i,j+1,k));
    }
    return dp[i][j][k]=res;
}
int main()
{
    ll k;
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    
    F(i,0,n-1)
    cin>>a[i];
    
    F(j,0,m-1)
    cin>>b[j];
    
    ll ans=korderlcs(0,0,k);
    cout<<ans<<endl;

    return 0;
}

