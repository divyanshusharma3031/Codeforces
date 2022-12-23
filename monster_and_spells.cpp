#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(long long time[],long long health[], int n)
{

    vector<pair<long long,long long>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({time[i]-health[i]+1,time[i]});
    }
    long long ans=0;
    sort(v.begin(),v.end());
    long long l=v[0].first;
    long long r=v[0].second;
    for(int i=1;i<v.size();i++)
    {
        if(r>=v[i].first)
        {
            r=max(r,v[i].second);
        }
        else
        {
            ans+=((r-l+1)*(r-l+2))/2;
            l=v[i].first;
            r=v[i].second;
        }
    }
    ans+=((r-l+1)*(r-l+2))/2;
    cout<<ans<<"\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long long time[n];
        for(int i = 0; i < n; i++)
        {
            cin >> time[i];
        }
        long long health[n];
        for(int i = 0; i < n; i++)
        {
            cin >> health[i];
        }

        solve(time,health, n);
    }
}