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
int bs(vector<int> &arr, int target, int end)
{
    if (target > arr[end - 1])
        return end - 1;

    int start = 0;

    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= target)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vector<int> arr(n, 0);
    vector<int> que(q, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> que[i];
    }
    vector<int> x(n, 0);
    x[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        x[i] = max(arr[i], x[i - 1]);
    }
    vector<int> pref(n, 0);
    pref[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + arr[i];
    }
    for (auto it : que)
    {
        auto y=upper_bound(x.begin(),x.end(),it);
        int idx=y-x.begin();
        idx--;
        if(idx<0)
        {
            cout<<"0 ";
        }
        else if(idx>=n)
        {
            cout<<pref[n-1]<<" ";
        }
        else
        {
            cout<<pref[idx]<<" ";
        }
    }
    cout << "\n";
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