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
int solve(int i, int n, vector<vi> &arr, int choose,vii &dp)
{
    if (i >= n)
    {
        return 0;
    }
    if(dp[i][choose]!=-1)
    {
        return dp[i][choose];
    }
    if (choose == 0)
    {
        return dp[i][choose]=max({arr[0][i] + solve(i + 1, n, arr, 1,dp), arr[1][i] + solve(i + 1, n, arr, 2,dp), solve(i + 1, n, arr, choose,dp)});
    }
    if (choose == 1)
    {
        return dp[i][choose]=max({arr[1][i] + solve(i + 1, n, arr, 2,dp), solve(i + 1, n, arr, choose,dp)});
    }
    return dp[i][choose]=max({arr[0][i] + solve(i + 1, n, arr, 1,dp), solve(i + 1, n, arr, choose,dp)});
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    vector<vector<int>> arr(2, vector<int>(n, 0));
    vector<vector<int>> dp(n+1,vector<int>(3,-1));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << solve(0, n, arr, 0,dp) << "\n";
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
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