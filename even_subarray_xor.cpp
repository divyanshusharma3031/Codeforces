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
    vi a(n+2,0);
    vi b(n+2,0);
    if(n==2)
    {
        cout<<"1 2\n";
        cout<<"4 7\n";
        return;
    }
    a[1]=1;
    a[2]=2;
    b[1]=4;
    b[2]=7;
    int x=16;
    for(int i=3;i<=n;)
    {
        
    }
    int x1=0;
    int x2=0;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<"\n";
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