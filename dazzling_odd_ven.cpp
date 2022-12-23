#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

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
    vector<ll> even;
    vector<ll> odd;

    ll e = 0;

    ll o = 0;

    for (ll i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even.push_back(arr[i]);
            e += arr[i];
        }
        else
        {
            odd.push_back(arr[i]);
            o += arr[i];
        }
    }
    ll x = n / 2;
    if (o % x == 0 && e % x == 0)
    {
        o = o / x;
        e = e / x;
        if (o % 2 == 0 || e % 2)
        {
        }
        else
        {
            cout << "YES\n";
            return;
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    vector<int> od;
    vector<int> ed;
    for (int i = 0; i < odd.size() - 1; i++)
    {
        od.push_back(odd[i + 1] - odd[i]);
        ed.push_back(even[i + 1] - even[i]);
    }

    sort(od.begin(), od.end());

    sort(ed.begin(), ed.end());

    for (int i = 0; i < od.size(); i++)
    {
        // cout << od[i] << " " << ed[i] << "\n";
        if (od[i] != ed[i])
        {
            cout << "NO\n";
            return;
        }
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
        vector<ll> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}