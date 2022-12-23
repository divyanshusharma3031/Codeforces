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
// #define int long long
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;

void solve()
{
    ll n;
    cin >> n;
    vi a(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bool b=true;
    vector<double> arr(n,0);
    for(int i=0;i<n;i++)
    {
        arr[i]=a[i]/(2.0);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=int(arr[i]))
        {
            if(b)
            {
                arr[i]=ceil(arr[i]);
            }
            else
            {
                arr[i]=floor(arr[i]);
            }
            b=!b;
        }
    }
    for(int i=0;i<n;i++)
    {
        a[i]=arr[i];
        cout<<a[i]<<"\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}