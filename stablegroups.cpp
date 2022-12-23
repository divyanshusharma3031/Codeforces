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
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    ll k;
    ll x;
    cin >> k >> x;
    vi arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> v;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff <= x)
        {
        }
        else
        {
            if (x == 0)
            {
                // do nothing
                ans++;
                // c++;
            }
            else
            {
                int diff = (arr[i] - arr[i - 1]);
                int ele = (diff / x);
                if (diff % x == 0)
                {
                    v.push_back(ele - 1);
                    continue;
                }
                v.push_back(ele);
            }
        }
    }
    sort(v.begin(), v.end());
    ans = ans + v.size();
    for (int i = 0; i < v.size(); i++)
    {
        k = k - v[i];
        if (k < 0)
        {

            break;
        }
        else
        {
            ans--;
        }
    }
    cout << ans << "\n";
}
int32_t main()
{
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