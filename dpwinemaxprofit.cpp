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
int maxprofitusingbottomup(int a[],int n)
{
    int dp[100][100]={};
    int year=n;
    for(int i=0;i<n;i++)
    {
        dp[i][i]=year*a[i];
    }
    --year;
    for(int len=2;len<=n;len++)
    {
        int strt=0;
        int end=n-len;
        while(strt<=end)
        {
            int endwindow=strt+len-1;
            dp[strt][endwindow]=max(
                a[strt]*year+dp[strt+1][endwindow],
                a[endwindow]*year+dp[strt][endwindow-1]
                );
                
            strt++;    
        }
        --year;
        
    }
    return dp[0][n-1];
}

int main()
{
  
   int n;
   cin>>n;
   int a[n];
   for (int i=0;i<n;i++) {
       cin>>a[i];
   }
//   memset(memo,-1,sizeof(memo));
//   int ans=maxprofit(a,0,n-1,1);
     
   cout<<maxprofitusingbottomup(a,n)<<endl;

    return 0;
}

