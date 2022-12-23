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
    string s;
    cin >> s;
    string a;
    string b;
    a += "1";
    b += "1";
    int i = 1;
    while (i < n && (s[i] == '2' || s[i] == '0'))
    {
        if (s[i] == '0')
        {
            a += "0";
            b += "0";
        }
        else
        {
            a += "1";
            b += "1";
        }

        i++;
    }
    if (i < n && s[i] == '1')
    {
        a += "1";
        b += "0";
        i++;
    }
    for (; i < n; i++)
    {
        if (s[i] == '1')
        {
            a += "0";
            b += "1";
        }
        else if (s[i] == '2')
        {
            a += "0";
            b += "2";
        }
        else
        {
            a += "0";
            b += "0";
        }
    }
    cout << a << "\n";
    cout << b << "\n";
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