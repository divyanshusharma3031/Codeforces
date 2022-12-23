#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
void reverse(int lo, int hi, vector<int> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<ll> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    ll e = m;
    while (e--)
    {
        ll c;
        cin >> c;
        ll x;
        cin >> x;
        // x=x;
        while (x--)
        {
            ll w;
            cin >> w;
            ll c2;
            cin >> c2;
            arr[c2] = (arr[c2] + w * arr[c]) % mod;
        }
        arr[c] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << "\n";
    }
}
