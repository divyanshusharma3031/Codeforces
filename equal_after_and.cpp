#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

void reverse(ll lo, ll hi, vector<ll> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}

bool palindrome(string s)
{
    ll i = 0;
    ll n = s.length() - 1;
    if (n == 0)
    {
        return false;
    }
    while (i <= n)
    {
        if (s[i] != s[n])
        {
            return false;
        }

        i++;
        n--;
    }
    return true;
}
ll binaryToDecimal(vector<ll> arr)
{
    vector<ll> num = arr;
    ll dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    ll base = 1;

    ll len = num.size();
    for (ll i = len - 1; i >= 0; i--)
    {
        if (num[i] == 1)
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> v(32, 0);
    ll mx = -1;
    ll m = -1;
    for (ll i = 0; i < n; i++)
    {
        m = max(m, arr[i]);
        for (ll j = 0; j < 32; j++)
        {
            if (((arr[i]) & (1 << j)))
            {
                v[j]++;
            }
        }
    }
    vector<ll> a(32, 0);
    for (ll i = 0; i < 32; i++)
    {
        if (v[i] == n)
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 0;
        }
    }
    reverse(a.begin(), a.end());
    ll num = binaryToDecimal(a);
    ll x = arr[0];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        x = x & arr[i];
        if (x != num)
        {
            ans++;
        }
        else
        {
            if (i != n - 1)
                x = arr[i + 1];
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}