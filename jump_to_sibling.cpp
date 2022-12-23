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

void solve(vector<ll> &arr, ll n)
{
    ll odd = 0;
    ll even = 0;
    vector<ll> e;
    vector<ll> o;
    vector<ll> co;
    vector<ll> ce;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2)
        {
            odd++;
            o.push_back(i);
        }
        else
        {
            even++;
            e.push_back(i);
        }
        ce.push_back(even);
        co.push_back(odd);
    }
    if ((arr[0] % 2) == (arr[arr.size() - 1] % 2))
    {
        if (arr[0] % 2 == 0)
        {
            cout << (even - 1) << "\n";
        }
        else
        {
            cout << (odd - 1) << "\n";
        }
        return;
    }
    else
    {
        if ((arr[0] % 2) == 0)
        {
            ll ans = 1e18;
            for (ll i = 0; i <n; i++)
            {
                ans = min(ans, odd - co[i] + i);
            }
            cout<<ans<<"\n";
            return;
        }
        if ((arr[0] % 2))
        {
            ll ans = 1e18;
            for (ll i = 0; i < n; i++)
            {
                cout<<even-ce[i]+i<<"\n";
                ans = min(ans, even - ce[i] + i);
            }
            cout<<ans<<"\n";
            return;
        }
    }
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
        vector<ll> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}