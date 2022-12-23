#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void reverse(int lo, int hi, vector<int> &arr)
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
    int i = 0;
    int n = s.length() - 1;
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

void solve(vector<ll> &arr, ll n, ll m)
{
    if (n > m)
    {
        cout << "NO\n";
        return;
    }
    sort(arr.begin(), arr.end());
    if (n == 1)
    {
        if (arr[0] >= (2 * arr[0] + 1))
        {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
    ll s = 0;
    ll c = 1;
    for (int i = 1; i < n; i++)
    {
        s += arr[i];
        s++;
    }
    s+=arr[arr.size()-1];
    s++;
    if (s > m)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll m;
        cin >> m;
        vector<ll> arr;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            arr.push_back(x);
        }
        solve(arr, n, m);
    }
}