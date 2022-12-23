#include<bits/stdc++.h>
using namespace std;
int solve(int books[],int prices[],int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int k;
    cin>>k;
    int books[n];
    int prices[n];
    for(int i=0;i<n;i++)
    {
        cin>>books[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    cout<<solve(books,prices,n);
}