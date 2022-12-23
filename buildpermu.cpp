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
int mySqrt(int x)
{
    int lo = 0;
    int hi = 1e9;
    int mid = 0;
    while (lo <= hi)
    {

        mid = (lo + hi) / 2;
        if (x < mid * mid)
        {
            hi = mid - 1;
            mid--;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return mid;
}
void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    vector<int> arr(n,-1);
    set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(i*i);
    }
    int i=n-1;
    while(i>=0)
    {
        int sq=*s.lower_bound(i);
        int pos=sq-i;
        int val=i;
        while(pos<n && val>=0 && arr[pos]==-1)
        {
            arr[pos]=val;
            pos++;
            val--;
        }
        i=val;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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