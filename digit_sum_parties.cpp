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
void solve(ll n)
{
    if (n % 10 == 9)
    {
        ll x = n + 1;
        ll y = n;
        ll s1 = 0;
        ll s2 = 0;
        while (y)
        {
            s1 += y % 10;
            y = y / 10;
        }
        while (x)
        {
            s2 += x % 10;
            x = x / 10;
        }
        ll z = n + 2;
        ll s3 = 0;
        while (z)
        {
            s3 += x % 10;
            z = z / 10;
        }
        if (s1 % 2)
        {
            if (s2 % 2 == 0)
            {
                cout << n + 1 << "\n";
            }
            else
            {
                cout << n + 2 << "\n";
            }
        }
        else
        {
            if (s2 % 2)
            {
                cout << n + 1 << "\n";
            }
            else
            {
                cout << n + 2 << "\n";
            }
        }
        return;
    }
    cout << n + 1 << "\n";
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
        solve(n);
    }
}