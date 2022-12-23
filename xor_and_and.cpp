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
    int ans = 0;
    sort(arr.begin(), arr.end());
    int c = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int x = log2(arr[i]);
        int y = log2(arr[i + 1]);
        if (x == y)
        {
            c++;
        }
        else
        {
            ans += c * (c - 1) / 2;
            c=1;
        }
    }
    if(c!=1)
    {
        ans += c * (c - 1) / 2;   
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
        vector<ll> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}
