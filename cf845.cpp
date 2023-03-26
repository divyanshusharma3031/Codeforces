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
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1] && s[i] == 'a')
        {
            cout << "2\n";
            return;
        }
    }
    // there are no two consecutive a's
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            v.push_back(i);
        }
    }
    string a = "abbacca";
    string b = "accabba";
    string c = "aba";
    string d = "aca";
    string e = "abca";
    string f = "acba";
    int ans2 = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        string ans = "";
        for (int j = i; j < min(i + 7, n); j++)
        {
            ans += s[j];
            if (c == ans || d == ans)
            {
                ans2 = min(ans2, j - i + 1);
            }
            if (e == ans || f == ans)
            {
                ans2 = min(ans2, j - i + 1);
            }
            if (ans == a || ans == b)
            {
                ans2 = min(ans2, 7ll);
            }
        }
    }
    if (ans2 == INT_MAX)
    {
        cout << "-1\n";
        return;
    }
    cout << ans2 << "\n";
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