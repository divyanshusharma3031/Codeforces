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

void solve(vector<ll> arr, ll n)
{
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    if (n == 1)
    {
        if (arr[0] == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }
    if ((arr[0] - arr[1]) > 1)
    {
        cout << "NO\n";
        return;
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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}
