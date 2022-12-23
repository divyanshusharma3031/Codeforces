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
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;

void solve()
{
    ll n;
    cin >> n;
    double x=log2(n);
    if(x==int(x))
    {
        cout<<"0\n";
        return;
    }
    int ans=0;
    while(n>1)
    {
        int a=log2(n);
        int p=ceil(pow(2,a));
        n=n-p;
        x=log2(n);
        if(x==int(x))
        {
            ans++;
            break;
        }
        ans++;
    }
    cout<<ans<<"\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}