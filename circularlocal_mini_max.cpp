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
    vi arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<ll> v1;
    vector<ll> v2;
    if (n % 2 == 0)
    {

        for (int i = 0; i < n / 2; i++)
        {
            v1.push_back(arr[i]);
        }
        for (int i = n / 2; i < n; i++)
        {
            v2.push_back(arr[i]);
        }
        vector<int> v3;
        int i = 0;
        int j = 0;
        while (i < v1.size() && j < v2.size())
        {
            v3.push_back(v1[i]);
            v3.push_back(v2[j]);
            i++;
            j++;
        }
        while (i < v1.size())
        {
            v3.push_back(v1[i]);
            i++;
        }
        while (j < v2.size())
        {
            v3.push_back(v2[j]);
            j++;
        }
        bool b = false;
        for (int i = 0; i < n; i++)
        {
            if (v3[(i - 1 + n) % n] < v3[i] && v3[i] > v3[(i + 1) % n])
            {
            }
            else if (v3[(i - 1 + n) % n] > v3[i] && v3[i] < v3[(i + 1) % n])
            {
            }
            else
            {
                // cout<<i<<"\n";
                b = true;
                break;
            }
        }
        if(b)
        {
            cout<<"NO\n";
            return;
        }
        cout << "YES\n";
        for (int i = 0; i < v3.size(); i++)
        {
            cout << v3[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout<<"NO\n";
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