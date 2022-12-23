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

void solve(vector<ll> &l, vector<ll> &r, ll n)
{
    vector<pair<ll, ll>> v;
    for (ll i = 1; i <= n; i++)
    {
        v.push_back({l[i], i - 1});
        v.push_back({r[i], i + 1});
    }
    set<int> s;
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }

    ll ans = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        if (s.size() <= 1)
        {
            break;
        }
        else if (v[i].second < (*s.begin()) || v[i].second > *(s.rbegin()))
        {
            continue;
        }
        else
        {
            // cout<<v[i].first<<" ";
            if (s.find(v[i].second) != s.end())
            {
                ans += v[i].first;
                s.erase(v[i].second);
                i=0;
            }
        }
    }
    cout << ans << "\n";
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
        vector<ll> r(n + 1, 0);
        vector<ll> l(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> r[i];
        }
        solve(l, r, n);
    }
}