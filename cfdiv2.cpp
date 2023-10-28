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
    vector<pi> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int y;
        cin >> y;
        v.push_back({x, y});
    }
    ll ans = v[0].second;
    ll c=1;
    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    int gcd=v[0].first*v[0].second;
    for (int i = 1; i < n; i++)
    {
        ans = (((v[i].second * ans)) /
               (__gcd(v[i].second, ans)));
        gcd=__gcd(gcd,v[i].first*v[i].second);
        if(gcd%ans)
        {
            c++;
            ans=v[i].second;
            gcd=v[i].first*v[i].second;
        }
    }
    cout<<c<<"\n";
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