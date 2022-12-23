#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include<numeric>
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
int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
void solve()
{
    ll n;
    cin >> n;
    if(n==2)
    {
        cout<<"0\n";
        return;
    }
    if(n%2==0)
    {
        cout<<((n/2+1)*(n/2-1))-1<<"\n";
    }
    else
    {
        cout<<((n/2+1)*(n/2-1))-1<<"\n";
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