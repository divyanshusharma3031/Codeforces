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
    vector<int> answer;
    if (n == 0)
    {
        answer.push_back(0);
        return answer;
    }
    while (n > 0)
    {
        int rem = n % 2;
        answer.push_back(rem);
        n = n / 2;
    }
    return answer;
}

bool f(vi a, ll t, ll n)
{

    ll count = 0;
    for (int i = 0; i < t; i++)
        count += a[i];

    ll mx = 0;
    for (int i = t; i < n; i++)
        mx = max(a[i], mx);

    ll l = 0;
    for (int i = t; i < n; i++)
        l += abs(a[i] - mx);

    if (count >= l)
        return true;

    return false;
}
ll answer(vi a, ll n)
{

    ll l = 0, h = n;
    ll ans = 0;
    while (h >= l)
    {
        ll Ix = (l + h) / 2;
        if (f(a, Ix, n))
        {
            h = Ix - 1;
            ans = Ix;
        }
        else
        {
            l = Ix + 1;
        }
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    vi arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll c1 = answer(arr, n);
    reverse(arr.begin(),arr.end());
    ll c2=answer(arr, n);
    cout<<min(c1,c2)<<"\n";
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