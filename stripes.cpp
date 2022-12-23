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
    vector<string> v;
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    // checking everyrow
    for (int i = 0; i < 8; i++)
    {
        int r = 0;
        int b = 0;
        for (int j = 0; j < 8; j++)
        {
            if (v[i][j] == 'R')
            {
                r++;
            }
            else if(v[i][j]=='B')
            {
                b++;
            }
        }
        if (r == 8)
        {
            cout << "R\n";
            return;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        int r = 0;
        int b = 0;
        for (int j = 0; j < 8; j++)
        {
            if (v[j][i] == 'R')
            {
                r++;
            }
            else if(v[j][i]=='B')
            {
                b++;
            }
        }
        if (b == 8)
        {
            cout << "B\n";
            return;
        }
    }
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