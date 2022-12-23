#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"

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
    ll s=0;
    for(int i=0;i<n;i++)
    {
        s+=arr[i]-1;
    }
    if(s%2)
    {
        cout<<"errorgorn"<<"\n";
    }
    else
    {
        cout<<"maomao90"<<"\n";
    }
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
        vector<ll> arr(n,0);
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
    }
}