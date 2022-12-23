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
bool sign(int n)
{
    return n>=0;
}

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin>>s;
    if(palindrome(s))
    {
        cout<<"0\n";
        return;
    }
    int mn=1e9;
    for(char i='a';i<='z';i++)
    {
        int j=0;
        int k=n-1;
        int a=0;
        // cout<<i<<"\n";
        bool b=true;
        while(j<=k)
        {
            if(s[j]==s[k])
            {
                j++;
                k--;
            }
            else if(s[j]==i)
            {
                j++;
                a++;
            }
            else if(s[k]==i)
            {
                k--;
                a++;
            }
            else
            {
                b=false;
                break;
            }
        }
        if(b)
        {
            mn=min(mn,a);
        }
    }
    if(mn==1e9)
    {
        cout<<"-1\n";
        return;
    }
    cout<<mn<<"\n";
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