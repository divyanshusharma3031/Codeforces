#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define int long long

#define endl "\n"

typedef long long ll;

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
    
    cin >> n;
    
    vi arr(n,0);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int s=0;

    for(int i=0;i<n;i++)
    {
        s+=arr[i];
    }

    double k=s/(n/1.0);

    // cout<<k<<"\n";

    double s1=(n-2)*k;

    

    double f=s-s1;

    map<double,int> mpp;

    int c=0;

    for(int i=0;i<n;i++)
    {
        if(mpp[f-arr[i]])
        {
            c+=mpp[f-arr[i]];
        }
        mpp[arr[i]]++;
    }
    cout<<c<<"\n";
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
}