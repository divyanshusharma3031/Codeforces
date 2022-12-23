#include<bits/stdc++.h>
using namespace std;
vector<long long> ans;
void helper()
{
    for(int i=0;i<17;i++)
    {
        for(int j=i+1;j<18;j++)
        {
            for(int k=j+1;k<19;k++)
            {
                for(int l=k+1;l<20;l++)
                {
                    long long x=(1LL<<i)+(1LL<<j)+(1LL<<k)+(1LL<<l);
                    ans.push_back(x);
                    if(ans.size()==1000)
                    {
                        break;
                    }
                }
            }
        }
    }
}
void solve(int n)
{
    for(int i=0;i<n;i++)
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
    helper();
    while(t--)
    {
        int n;
        cin>>n;
        solve(n);
    }
}