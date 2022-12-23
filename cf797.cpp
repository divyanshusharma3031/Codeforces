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
    cin>>n;
    if(n%3==0)
    {
        cout<<n/3<<" "<<n/3+1<<" "<<n-n/3-n/3-1<<"\n";
    }
    else if(n%3==1)
    {
        cout<<n/3<<" "<<n/3+2<<" "<<n-n/3-n/3-2<<"\n";
    }
    else
    {
        cout<<n/3+1<<" "<<n/3+2<<" "<<n-n/3-n/3-3<<"\n";
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
        solve();
    }
}