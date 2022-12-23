#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
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
    cin >> n;
    ll k;
    cin>>k;
    // ye k banana hai
    vector<vector<int>> v;
    int i=0;
    int t=0;
    int st=1e6;
    while(i<n)
    {
        ll l;
        ll r;
        cin>>l;
        cin>>r;
        v.push_back({l,r});
        t=max(t,r);
        st=min(st,l);
        i++;
    }
    //can i make the final array in O(1)
    // yes i can
    //  t-1 is our end point yaha se aage traverse nahi karna
    // st-1 is our initial treversing point.

    vi c(100,000,0);
    

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