#include<bits/stdc++.h>
using namespace std;
int longestincsequence(int a[100],int n)
{
    int dp[100];
    
    for(int i=0;i<n;i++) dp[i]=1;
    
    int best=-1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<=a[i])
            {
                int curlen=1+dp[j];
                dp[i]=max(curlen,dp[i]);
            }
        }
        best=max(best,dp[i]);
    }
    return best;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++)
		cin>>a[i];
// 	for(int i=0;i<1000;i++)
// 		memo[i]=-1;
	int ans=longestincsequence(a,n);
	cout<<ans<<endl;
}
