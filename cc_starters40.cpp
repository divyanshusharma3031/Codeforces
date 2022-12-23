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
    if(n==1)
    {
        cout<<"0\n";
        return;
    }
    if(n<=4)
    {
        cout<<"1\n";
        return;
    }

    int x=(n-1)/5;

    x=x*2;

    int y=(n-1)%5;
    if(y==0)
    {

    }
    else if(y<=3)
    {
        x+=1;
    }
    else
    {
        x+=2;
    }
    cout<<x<<"\n";
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