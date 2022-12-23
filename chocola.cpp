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
    int n;
    int m;
    cin >> m >> n;

    vector<int> x(m - 1, 0);

    vector<int> y(n - 1, 0);

    for (int i = 0; i < m - 1; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> y[i];
    }

    int i = 0;

    int j = 0;

    int ans = 0;

    int vc = 1;
    int hc = 1;

    m--;
    n--;

    sort(x.begin(), x.end(), greater<int>());

    sort(y.begin(), y.end(), greater<int>());
    while (i < m && j < n)
    {
        if (x[i] >= y[j])
        {
            ans = ans + x[i] * vc;
            i++;
            hc++;
        }
        else
        {
            ans = ans + y[j] * hc;
            j++;
            vc++;
        }
    }

    while (i < m)
    {
        ans = ans + x[i] * vc;
        i++;
    }

    while (j < n)
    {
        ans = ans + y[j] * hc;
        j++;
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