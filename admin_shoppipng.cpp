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
ll comb(int n, int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            // gcd of p, k
            long long m = __gcd(p, k);

            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }

    else
        p = 1;

    // if our approach is correct p = ans and k =1
    return p;
}
void solve(vector<ll> &arr, ll n, ll x)
{
    ll idx=-1;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] >= x)
        {
            idx = i;
            break;
        }
    }
    sort(arr.begin(), arr.end());
    int mx=ceil(x/(arr[0]/(1.0)));
    int mn=n;
    cout<<max(mn,mx)<<"\n";
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
        ll x;
        cin >> x;
        vector<ll> arr(n, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n, x);
    }
}