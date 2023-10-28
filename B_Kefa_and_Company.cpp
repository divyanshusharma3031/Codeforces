// template taken from Striver_79
// Remember you were also a novice when you started
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure.
// The goal is to solve problems most efficiently not just barely
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
void myerase(ordered_set &t, int v)
{
    int rank = t.order_of_key(v);                     // Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); // Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
int power(long long x, unsigned int y, int p=1e9+7)
{
    int res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    ll d;
    cin>>d;//isse less than difference hona chaiye
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        int f;
        cin>>f;
        v.push_back({m,f});
    }
    sort(v.begin(),v.end(),[&](pair<int,int> &p1,pair<int,int> &p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    });
    vector<int> pref(n+1,0);
    vector<int> ahead;
    for(int i=1;i<=n;i++)
    {
        ahead.push_back(v[i-1].first);
        pref[i]=pref[i-1]+v[i-1].second;
    }
    int ans=0;
    vector<int> back;
    for(int i=0;i<n;i++)
    {
        int idx2=upper_bound(ahead.begin(),ahead.end(),v[i].first+d-1)-ahead.begin();
        int ans2=pref[idx2]-pref[i];
        ans=max(ans,ans2);
        back.push_back(v[i].first);
    }
    cout<<ans<<"\n";
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}