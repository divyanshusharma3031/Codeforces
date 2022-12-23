#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
typedef long long ll;
#define foa(i,k,n) for(int i = k; i < n; i++)
typedef vector<ll> vi;
void reverse(int lo, int hi, vector<int> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}
bool sign(int n)
{
    return n >= 0;
}
inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}
vi getbinary(int n)
{
    vector<int> ans;
    if (n == 0)
    {
        ans.push_back(0);
        return ans;
    }
    while (n > 0)
    {
        int rem = n % 2;
        ans.push_back(rem);
        n = n / 2;
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    vi arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ans = 0;

    vi pref = arr;

    for (int i = 1; i < n; i++)
    {
        pref[i] += pref[i - 1];
    }

    vi pow2(42,1);
	foa(i,1,42){
		pow2[i] = pow2[i-1] * 2ll;
	}
    for (int i = 1; i < 42; i++)
    {
        pow2[i] = pow2[i - 1] * 2ll;
    }
    vector<int> suff(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if ((j - i) > 40)
            {
                break;
            }
            // cout<<j-i+1<<" ";
            suff[i] = suff[i] + arr[j]/pow2[j-i+1] ;
        }
        // cout<<"\n";
    }
    ans = suff[0];
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, pref[i] - k * (i + 1) + suff[i+1]);
    }
    ans = max(ans, pref[n - 1] - k * n);
    cout << ans << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}