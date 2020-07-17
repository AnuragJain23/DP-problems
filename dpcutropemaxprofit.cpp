#include<bits/stdc++.h>
using namespace std;
int memo[1000];
int maxprofit(int a[],int totallen)
{
	if(totallen==0) return 0;
	if(memo[totallen]!=-1) return memo[totallen];

	int best=0;
	for(int len=1;len<=totallen;len++)
	{
		int netprofit=a[len]+maxprofit(a,totallen-len);
		best=max(best,netprofit);
	}
	memo[totallen]=best;
	return memo[totallen];
}
int maxprofit_bu(int a[],int totallen)
{
    int dp[100]={0};
    
    for(int len=1;len<=totallen;len++)
    {
        int best=0;
        for(int cut=1;cut<=len;cut++)
        {
            best=max(best,a[cut]+dp[len-cut]);
        }
        dp[len]=best;
    }
    return dp[totallen];
}
int main()
{
	int priceofeachlen[100];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>priceofeachlen[i];
	for(int i=0;i<1000;i++)
		memo[i]=-1;
	int ans=maxprofit_bu(priceofeachlen,n);
	cout<<ans<<endl;
}
