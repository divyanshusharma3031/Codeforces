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
    
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    if(is_sorted(arr.begin(),arr.end()))
    {
        cout<<0<<"\n";
        return;
    }
    
    vi arr2=arr;
    
    reverse(arr2.begin(),arr2.end());
    
    if(is_sorted(arr2.begin(),arr2.end()))
    {
        cout<<0<<"\n";
        return;
    }
    int j=n-1;
    while(j>0 && arr[j]<=arr[j-1])
    {
        j--;
    }
    // increasing from back
    while(j>0 && arr[j]>=arr[j-1])
    {
        j--;
    }
    cout<<j<<"\n";
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