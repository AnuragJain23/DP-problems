#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[5]={4,2,3,1,3};
    int dp[200][200]={0};
    int n=4;
    for(int i=1;i<n;i++)
    {
        int r=0,c=i;
        while(c<n)
        {
            int val=INT_MAX;
            for(int pivot=r;pivot<c;pivot++)
            {
                val=min(val,dp[r][pivot]+dp[pivot+1][c]+arr[r]*arr[pivot+1]*arr[c+1]);
            }
            dp[r][c]=val;
            r++;c++;
        }
    }
    cout<<dp[0][n-1];
}

