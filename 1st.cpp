#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

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
void solve(vector<ll> arr,ll n,ll x)
{
    ll mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,arr[i]);
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans+ceil(arr[i]/(x/1.0));
    }
    cout<<min(ans,mx)<<"\n";
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
        cin>>x;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n,x);
    }
}