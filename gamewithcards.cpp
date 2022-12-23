#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
typedef long long ll;
typedef vector<ll> vi;
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
    ll n;
    cin >> n;
    vi arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll m;
    cin >> m;
    vi arr2(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());
    if (arr[n - 1] >= arr2[m - 1])
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
    }
    if (arr2[m - 1] >= arr[n - 1])
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Alice\n";
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