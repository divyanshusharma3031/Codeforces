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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==0 && b==0 && c==0 && d==0)
    {
        cout<<0<<"\n";
        return;
    }
    if(a==0)
    {
        cout<<1<<"\n";
        return;
    }
    if(b==0 && c==0)
    {
        int ans=a;
        ans=ans+min(d,a);
        d=d-a;
        if(d>0)
        {
            ans++;
        }
        cout<<ans<<"\n";
        return;
    }
    int ans=a;
    ans=ans+2*min(b,c)+min(a+1,abs(b-c)+d);
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