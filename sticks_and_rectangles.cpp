#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

void solve(vector<ll> &arr, ll n)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    int x = 0;
    int y = 0;
    for (auto it : mpp)
    {
        x += (it.second) % 2;
        y += it.second / 2;
    }
    // cout<<y<<"\n";
    if (y % 2)
    {
        if(x==0)
        {
            cout<<2<<"\n";
        }
        else if (x % 2)
        {
            cout << x  << "\n";
        }
        else
        {
            cout << x +2<< "\n";
        }
    }
    else
    {
        if (x % 2)
        {
            cout << x + 2 << "\n";
        }
        else
        {
            cout << x << "\n";
        }
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
        ll n;
        cin >> n;
        vector<ll> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}