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

void solve(vector<ll> &arr,ll n)
{
    int e=0;
    int o=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2)
        {
            o++;
        }
        else
        {
            e++;
        }
    }
    if(e==n || o==n)
    {
        cout<<"YES\n";
        return;
    }
    sort(arr.begin(),arr.end());
    bool one=false;
    bool con=false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            one=true;
        }
        if(i<n-1 && arr[i]==(arr[i+1]-1))
        {
            con=true;
        }
    }
    if(one && con)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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