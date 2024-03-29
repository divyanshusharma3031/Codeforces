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
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n; // no. of lines
    // y=kx means passes through origin
    ll m;
    cin >> m; // no . of parabolas
    vector<int> lines;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        lines.push_back(k);
    }
    vector<vector<int>> parabolas;
    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        parabolas.push_back({a, b, c});
    }
    sort(lines.begin(),lines.end());
    for (auto it : parabolas)
    {
        int product = 4ll * it[0] * it[2];
        auto x=lower_bound(lines.begin(),lines.end(),it[1])-lines.begin();
        if(x <n && ((it[1]-lines[x])*(it[1]-lines[x]))<product)
        {
            cout<<"YES\n";
            cout<<lines[x]<<"\n";
        }
        else if(x>0 && ((it[1]-lines[x-1])*(it[1]-lines[x-1]))<product)
        {
            cout<<"YES\n";
            cout<<lines[x-1]<<"\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}