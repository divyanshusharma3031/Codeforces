#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

typedef vector<ll> vi;

const int mod = 1e9 + 7;

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

void solve()
{
    ll n;
    cin >> n;
    vi a(n, 0);
    vi b(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> b[j];
    }

    vi d(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    vi done(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        done[d[i]] = 1;
    }
    vector<int> pos(n+1, -1);

    for (int i = 0; i < n; i++)
    {
        pos[a[i]] = i;
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            continue;
        }
        if (done[a[i]] || done[b[i]])
        {
            continue;
        }
        // cout<<a[i]<<" "<<b[i]<<"\n";
        vector<int> v;
        int curr = b[i];
        v.push_back(a[i]);
        bool flag = false;
        while (curr != a[i])
        {
            if (done[curr])
            {
                flag = true;
            }
            v.push_back(curr);
            curr = b[pos[curr]];
            if (done[curr])
            {
                flag = true;
            }
        }
        if (!flag)
        {
            ans = (ans * 2LL) % mod;
        }
        for (auto it : v)
        {
            // cout<<it<<" ";
            done[it] = 1;
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
        solve();
    }
}