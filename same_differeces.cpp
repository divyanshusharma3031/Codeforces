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

void solve(vector<ll> arr,ll n)
{
    map<int,int> mpp;
   long long ans=0;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        ans+=mpp[arr[i]-i];
        mpp[arr[i]-i]++;
    }
    cout<<ans<<"\n";
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
        vector<ll> arr(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
    }
}