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
    string s;
    cin>>s;
    map<char,int> mpp;
    for(int i=0;i<n;i++)
    {
        mpp[s[i]]++;
    }
    set<int> se;
    se.insert('a');
    se.insert('e');
    se.insert('i');
    se.insert('o');
    se.insert('u');
    ll ans=1;
    for(int i=0;i<n;i++)
    {
        if(se.find(s[i])!=se.end())
        {

        }
        else
        {
            if(s[i]=='c' || s[i]=='g' || s[i]=='l' || s[i]=='r')
            {
                ans=ans*2;
            }
        }
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
        solve();
    }
}