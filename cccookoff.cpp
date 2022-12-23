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
    ll l;
    ll r;
    cin >> l>>r;
    if(r<=4)
    {
        cout<<"-1\n";
        return;
    }
    else
    {
        for(int i=l+3;i<=r;i++)
        {
            ll x1=i^(i-1);
            ll x2=x1^(i-2);
            ll x3=x2^(i-3);
            if(x3==0)
            {
                cout<<i-3<<" "<<i-2<<" "<<i-1<<" "<<i<<"\n";
                return;
            }
        }
    }
    cout<<"-1\n";
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