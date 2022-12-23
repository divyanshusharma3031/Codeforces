#include <bits/stdc++.h>
using namespace std;
void solve(int n, int m)
{
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int mx=max(abs(n-1-i)+abs(m-1-j),max(abs(i-0)+abs(j-0),max(abs(n-1-i)+abs(j-0),abs(i-0)+abs(m-1-j))));
            ans.push_back(mx);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int m;
        cin >> n >> m;
        solve(n,m);
    }
}