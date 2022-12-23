#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>

using namespace std;

#define endl "\n"

typedef long long ll;

void reverse(ll lo, ll hi, vector<ll> &arr)
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
    ll i = 0;
    ll n = s.length() - 1;
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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<ll>());
    ll mx=arr[0];
    if (mx <= 3)
    {
        reverse(0, n - 1, arr);
    }
    int x=n-1;
    while(arr[x]==1 && x>=0)
    {
        cout<<arr[x]<<" ";
        x--;
    }
    for(ll i=0;i<=x;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}