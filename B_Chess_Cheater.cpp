// template taken from Striver_79
// Remember you were also a novice when you started
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
#define int long long
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    ll k;
    cin>>k;
    string s;
    cin>>s;
    int c=0;
    vector<int> pref(n+1,0);
    for(int i=0;i<n;i++)
    {
        pref[i]=c;
        if(s[i]=='W')
        {
            c++;
        }
        else
        {
            c=0;
        }
    }
    vi suff(n+1,0);
    c=0;
    for(int i=n-1;i>=0;i--)
    {
        suff[i]=c;
        if(s[i]=='W')
        {
            c++;
        }
        else
        {
            c=0;
        }
    }
    priority_queue<pi> pq;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        {
            pq.push({suff[i]+pref[i],i});
        }
    }
    while(k>0 && !pq.empty())
    {
        auto it=pq.top();
        s[it.second]='W';
        pq.pop();
        k--;
    }
    int ans=0;
    cout<<s<<" ";
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(s[i]=='W')
            {
                ans++;
            }
            continue;
        }
        else
        {
            if(s[i]=='W')
            {
                if(s[i-1]=='W')
                {
                    ans+=2;
                }
                else
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}