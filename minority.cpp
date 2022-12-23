#include<bits/stdc++.h>
using namespace std;
void solve(string s)
{
    int n=s.length();
    vector<int> zero(n,0);
    vector<int> one(n,0);
    int z=0;
    int o=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            z++;
        }
        else
        {
            o++;
        }
        zero[i]=z;
        one[i]=o;
    }
    vector<int> ans(n,0);
    for(int i=0;i<n;i++)
    {
        if(zero[i]!=one[i])
        {
            ans[i]=min(zero[i],one[i]);
        }
        else
        {
            ans[i]=0;
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans[n-1]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin>>s;
        solve(s);
    }
}