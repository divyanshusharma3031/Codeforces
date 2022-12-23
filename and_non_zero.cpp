#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> arr(200001,vector<int>(32,0));
void initiate()
{
    for(int i=1;i<=200000;i++)
    {
        for(int j=0;j<32;j++)
        {
            if(i&(1<<j))
            {
                arr[i][j]=1;
            }
            arr[i][j]+=arr[i-1][j];
        }
    }
}
int count(int l,int r)
{
    int mn=-1;
    for(int i=0;i<32;i++)
    {
        mn=max(mn,arr[r][i]-arr[l-1][i]);
    }
    return (r-l+1)-mn;
}
int main()
{
    int t;
    cin>>t;
    initiate();
    while(t--)
    {
        int l;
        cin>>l;
        int r;
        cin>>r;
        cout<<count(l,r)<<"\n";
    }
}