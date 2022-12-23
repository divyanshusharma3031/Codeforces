#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void solve(int idx,vector<vector<int>> &ans,int target,vector<int> &v,int n)
{
    if(idx>n)
    {
        return;
    }
    if(target==0)
    {
        ans.push_back(v);
        return;
    }
    if(target<0)
    {
        return;
    }

        v.push_back(idx);
        solve(idx,ans,target-idx,v,n);
        v.pop_back();
        solve(idx+1,ans,target,v,n);
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> ans;
    vector<int> v;
    solve(1,ans,n,v,n-1);
    for(int i=0;i<ans.size();i++)
    {
        for(auto j:ans[i])
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}