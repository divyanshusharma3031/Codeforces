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

void solve()
{
    ll n;
    ll m;
    cin >> n >> m;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    if (n == 1)
    {
        cout << "YES\n";
        return;
    }
    if (v[0][0] == 'R')
    {
        cout << "YES\n";
        return;
    }
    int l1 = INT_MAX;
    int u = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'R')
            {

                l1 = min(l1, abs(j));
                u = min(u, abs(i));
            }
        }
    }
    // cout << l1 << "\n";
    // cout << u << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'R')
            {
                int reql=j;
                int requ=i;
                if (j > l1)
                {
                    cout << "NO\n";
                    return;
                }
                else if(i>u)
                {
                    cout << "NO\n";
                    return;
                }
                else
                {
                    cout<<"YES\n";
                    return;
                }
            }
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
        solve();
    }
}