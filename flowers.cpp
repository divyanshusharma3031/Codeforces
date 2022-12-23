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
void solve(int i,int n,vi &red,vi &blue,int cr,int cb,int &ans,vector<vector<int>> &dp)
{
    if(i==n)
    {
        ans=max(ans,min(cr,cb));
        return;
    }
    if(dp[i][cr]>=cb)
    {
        return;
    }
    dp[i][cr]=cb;
    solve(i+1,n,red,blue,cr+red[i],cb,ans,dp);
    solve(i+1,n,red,blue,cr,cb+blue[i],ans,dp);
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    vector<int> red(n,0);
    vector<int> blue(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>red[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>blue[i];
    }
    int ans=0;
    vector<vector<int>> dp(n,vector<int>(20001,-1));
    solve(0,n,red,blue,0,0,ans,dp);
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