#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void reverse(long long lo, long long hi, vector<long long> &arr)
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
    long long i = 0;
    long long n = s.length() - 1;
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

void solve(string s, long long n, long long k)
{
    long long EXOR = 0;
    long long x = 0;

    long long i = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            EXOR = EXOR ^ 1;
        }
        if (EXOR == 0 && x < (k - 1))
        {
            x++;
            EXOR = 0;
        }
    }
    if (EXOR == 0 && x == k - 1)
    {
        cout << "YES\n";
        return;
    }
    EXOR = 0;
    i = 0;
    x = 0;
    for (; i < n; i++)
    {
        if (s[i] == '1')
        {
            EXOR = EXOR ^ 1;
        }
        if (EXOR == 1 && x < (k - 1))
        {
            x++;
            EXOR = 0;
        }
    }
    if (EXOR == 1 && x == k - 1)
    {
        cout<<"YES\n";
        return;
    }
    cout << "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        string s;
        cin >> s;
        solve(s, n, k);
    }
}