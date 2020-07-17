/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int memo[100][100];
int cnt=0;
int maxprofit(int a[],int be,int end,int year)
{
    cnt++;
    if(be>end)
    return 0;
    if(memo[be][end]!=-1) return memo[be][end];
    
    int q1=a[be]*year+maxprofit(a,be+1,end,year+1);
    int q2=a[end]*year+maxprofit(a,be,end-1,year+1);
    int ans=max(q1,q2);
    memo[be][end]=ans;
    return memo[be][end];
    
}
int mincost(int grid[][100],int n,int m)
{
    int dp[100][100]={};
    dp[0][0]=grid[0][0];
    
    for(int c=1;c<m;c++) dp[0][c]=dp[0][c-1]+grid[0][c];
    for(int r=1;r<n;r++) dp[r][0]=dp[r-1][0]+grid[r][0];
    
    for(int r=1;r<n;r++)
    {
        for(int c=1;c<m;c++)
        {
            dp[r][c]=min(
                dp[r-1][c],
                dp[r][c-1]
                )+grid[r][c];
        }
    }
    return dp[n-1][m-1];
}

int main()
{
  
   int n,m;
   cin>>n>>m;
   int grid[n][m];
   
   for (int i=0;i<n;i++) 
   {
       for(int j=0;j<m;j++)
       {
       cin>>grid[i][j];
       }
   }
   
   int ans=mincost(grid,n,m);
   cout<<ans<<endl;
   


    return 0;
}


