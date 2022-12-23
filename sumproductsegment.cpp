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
    ll x;
    ll y;
    cin >> x >> y;
    for (int i = 1; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            // calculating
            // min and max of i and y/il
            int a = min(i, y / i);
            int b = max(i, y / i);
            int c = a - 1;
            int d = x - c;
            // checking
            // for <=c;
            if (d <= c)
            {
                if (d < 0)
                {
                    c = x;
                    d = 0;
                }
                cout << a << " " << b << "\n";
                cout << min(c, d) << " " << max(c, d) << "\n";
                // print
                // the answer and return 
                return;
            }
            c=b+1;
            d=x-c;
            if(d>b)
            {
                 // print
                // the answer and return 
                cout<<a<<" "<<b<<"\n";
                cout<<min(c,d)<<" "<<max(c,d)<<"\n";
                return;
            }
        }
        
    }
    cout<<"-1\n";
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