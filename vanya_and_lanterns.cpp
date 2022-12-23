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

void solve(vector<ll> arr, ll l, ll n)
{
    sort(arr.begin(), arr.end());
    ll mx = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        mx = max(mx, arr[i] - arr[i - 1]);
    }
    ll mx2=INT_MIN;
    if(arr[0]!=0)
    {
        mx2=2*(arr[0]-0);
    }
    ll mx3=2*(l-arr[n-1]);
    double x=max({mx,mx2,mx3})/2.0;
    printf("%2f",x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll l;
    cin >> l;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve(arr, l, n);
}
