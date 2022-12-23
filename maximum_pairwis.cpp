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

void solve()
{
    ll n;

    ll m;


    cin>>n>>m;
    vector<ll> arr(n,0);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());

    // 1 2 3 4 5

    ll mx=INT_MIN;

    int i=0;

    int j=n-2;

    while(j>=0)
    {
        ll a=m;
        if(arr[j]!=0 && (arr[n-1]%arr[j])==0)
        {
            a=0;
        }
        mx=max({mx,arr[n-1]+arr[j]+(arr[n-1]-arr[j])%m,arr[n-1]+arr[j]+(arr[j]-arr[n-1])%m+a});
        j--;
    }

    cout<<mx<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}