#include <bits/stdc++.h>

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

void solve()
{
    ll n;
    ll q;
    cin >> n >> q;

    vector<ll> arr(n, 0);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll s = 0;

    map<ll, ll> vis;

    bool b=false;

    for (ll i = 0; i < n; i++)
    {
        s += arr[i];
    }
    ll ele = 0;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll v;

            cin >> v;

            ll r;

            cin >> r;
            if ((b) && (vis[v-1]==0))
            {
                s=s+(r-ele);
                arr[v - 1] = r;
                vis[v-1]=1;
            }
            else
            {
                s = s + (r - arr[v - 1]);
                arr[v - 1] = r;
            }
        }
        if (t == 2)
        {
            ll v;
            cin >> v;
            s = v * n;
            b = true;
            ele = v;
            vis.clear();
        }
        cout << s << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}