#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool subsum(vector<int> arr,int n,int sum,vector<vector<int>> &dp,vector<int> &ans)
{
    if(n<=0)
    {
        return false;
    }
    if(sum<0)
    {
        return false;
    }
    if(sum==0)
    {
        return true;
    }
    if((sum-arr[n-1])>=0)
    {
        ans.push_back(arr[n-1]);
        dp[n][sum]=subsum(arr,n-1,sum-arr[n-1],dp,ans);
        if(dp[n][sum])
        {
            return true;
        }
        ans.pop_back();
    }
    return dp[n][sum]=subsum(arr,n-1,sum,dp,ans);
}

int main()
{
    vector<int> arr(4,0);
    arr[0]=1;
    arr[1]=2;
    arr[2]=4;
    arr[3]=5;
    vector<int> ans;
    vector<vector<int>> dp(10,vector<int>(10,-1));
    subsum(arr,4,3,dp,ans);
    cout<<"hi"<<"\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"bye";
}