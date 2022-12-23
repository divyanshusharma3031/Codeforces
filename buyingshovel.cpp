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

vector<int> printDivisors(int n)
{
    // Note that this loop runs till square root
    vector<int> ans;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            if (n / i == i)
            {
                ans.push_back(i);
            }

            else // Otherwise print both
            {
                ans.push_back(n / i);
                ans.push_back(i);
            }
        }
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    int k;
    cin >> k;
    if (k >= n)
    {
        cout << 1 << "\n";
        return;
    }
    if (k == 1)
    {
        cout << n << "\n";
        return;
    }
    vi arr = printDivisors(n);
    int mn = n;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
        {
            mn = min(mn, n / arr[i]);
        }
    }
    cout << mn << "\n";
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