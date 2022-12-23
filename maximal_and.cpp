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
long long binaryToDecimal(vector<int> n)
{
    vector<int> num = n;
    long long dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    long long base = 1;

    long long len = num.size();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == 1)
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}
void solve(vector<ll> &arr, ll n, ll k)
{
    vector<int> v(31, 0);
    ll og = arr[0];
    for (ll i = 1; i < n; i++)
    {
        og = og & arr[i];
    }
    for (ll i = 0; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if ((arr[i] & (1 << j)))
            {
                v[j]++;
            }
        }
    }
    reverse(v.begin(), v.end());
    vector<int> Final(31, 0);
    for (int i = 0; i < 31; i++)
    {
        if ((n - v[i]) <= 0)
        {
            Final[i] = 1;
            continue;
        }
        else if ((n - v[i]) > k)
        {
            Final[i] = 0;
        }
        else
        {
            Final[i] = 1;
            k -= (n - v[i]);
        }
    }
    // reverse(0,Final.size()-1,Final);
    cout << max(binaryToDecimal(Final), og) << "\n";
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
        ll k;
        cin >> k;
        vector<ll> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n, k);
    }
}