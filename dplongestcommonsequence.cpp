#include<bits/stdc++.h>
using namespace std;
int longestcommonsequence(char X[],char Y[])
{
    int dp[100][100];
    int m=strlen(X);
    int n=strlen(Y);
    for(int i=0;i<=m;i++) dp[i][0]=0;
    for(int j=0;j<=n;j++) dp[0][j]=0;
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int q=0;
            if(X[i-1]==Y[j-1])
            {
                q=1+dp[i-1][j-1];
            }
            else
            {
                q=max(dp[i-1][j],dp[i][j-1]);
            }
            dp[i][j]=q;
        }
        
    }
    
    
    return dp[m][n];
}

int main()
{
	char X[100];
	char Y[100];
	
	cin>>X>>Y;
	
// 	for(int i=0;i<1000;i++)
// 		memo[i]=-1;
	int ans=longestcommonsequence(X,Y);
	cout<<ans<<endl;
}
