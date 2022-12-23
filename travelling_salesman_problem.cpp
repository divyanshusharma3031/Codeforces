#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int arr[4][4] = { {0, 10, 15, 20},
                      {5, 0, 9, 10},
                      {6, 13, 0, 12},
                      {8, 8, 9, 0} };
    
    int dp[4][4];
 int n=4;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=INT_MAX-1423;
        }
    }

   
    dp[1][1]=0;
    dp[2][2]=0;
    dp[3][3]=0;
    dp[4][4]=0;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                dp[i][j]=min(dp[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int solve(vector<vector<int>> &cost,int i,int depth,vector<vector<int>> &dp,vector<bool> &visited)
{
    int n=cost.size();
    if(depth==cost.size())
    {
        return cost[i][0];
    }
    visited[i]=true;
    int ans=INT_MAX;
    for(int j=0;j<n;j++)
    {
        if(!visited[j])
        {
            visited[j]=true;
            ans=min(ans,cost[i][j]+solve(cost,j,depth+1,dp,visited));
            visited[j]=false;
        }
    }
    visited[i]=false;
    return ans;
}
