// pure bullshit problem
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
int countDivisibles(int A, int B, int M)
{

    // Add 1 explicitly as A is divisible by M
    if (A % M == 0)
        return (B / M) - (A / M) + 1;

    // A is not divisible by M
    return (B / M) - (A / M);
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

    int l;
    int r;
    cin >> l >> r;
    int sqrt

    int ans = 0;
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