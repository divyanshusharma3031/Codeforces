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

void solve(vector<ll> &arr, ll n)
{
    vector<ll> aux(n, 0);
    for (ll i = 0; i < n; i++)
    {
        ll ans = 0;
        ll cnt2 = 0;
        ll mn = INT_MAX;
        ll x = arr[i];
        if(x%32768==0)
        {
            aux[i]=0;
            continue;
        }
        for (int j = 0; j <= 15; j++)
        {
            x = arr[i];
            cnt2 = 0;
            x += j;
            while (x % 2 == 0 && x>0)
            {
                x = x / 2;
                cnt2++;
            }
            mn = min({mn, 15 + j - cnt2,32768-arr[i]});
        }
        ans += mn;
        aux[i] = ans;
    }
    for (int i = 0; i < n; i++)
    {
        cout << aux[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);
}