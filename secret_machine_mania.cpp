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

void solve(ll x, ll c)
{
    if (c == 1)
    {
        cout << 1 << "\n";
        return;
    }
    ll prev = x;
    ll i = pow(2, log2(x) / c);
    do
    {
        prev=x;
        for (; i <= x; i++)
        {
            ll expr = pow(i, c);
            ll upper = expr / x;
            if ((upper) >= x)
            {
                break;
            }
            if ((expr % x) == 0)
            {
                x=expr/x;
                break;
            }
        }
        /* code */
    } while (prev!=x);
    cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        ll c;
        cin >> c;
        solve(x, c);
    }
}