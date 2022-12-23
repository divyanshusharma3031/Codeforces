#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

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
    cin>>n;
    vector<int> arr;
    ll x=n;
    while(n>0)
    {
        arr.push_back(n%10);
        n=n/10;
    }
    reverse(arr.begin(),arr.end());
    // cout<<arr[0]<<" "<<arr[1]<<"\n";
    if(arr.size()==2)
    {
        cout<<arr[1]<<"\n";
        return;
    }
    sort(arr.begin(),arr.end());
    cout<<arr[0]<<"\n";
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