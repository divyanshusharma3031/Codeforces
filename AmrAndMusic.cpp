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
void reverse(int lo, int hi, vector<int> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}
bool sign(int n)
{
    return n >= 0;
}
inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}
vi getbinary(int n)
{
    vector<int> ans;
    if (n == 0)
    {
        ans.push_back(0);
        return ans;
    }
    while (n > 0)
    {
        int rem = n % 2;
        ans.push_back(rem);
        n = n / 2;
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin>>k;
    vi arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vpi v;
    for(int i=0;i<n;i++)
    {
        v.push_back({arr[i],i});
    }
    sort(v.begin(),v.end());
    int c=0;
    vi ans;
    for(int i=0;i<n;i++)
    {
        if(k>=v[i].first)
        {
            k=k-v[i].first;
            ans.push_back(v[i].second);
        }
        else
        {
            break;
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
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