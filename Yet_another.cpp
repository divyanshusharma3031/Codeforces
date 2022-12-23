#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
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
bool sign(int n)
{
    return n >= 0;
}
inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
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
vi getbinary(int n)
{
    vector<int> ans;
    if (n == 0)
    {
        ans.push_back(0);
        return ans;
    }
    while (n > 0)
    {
        int rem = n % 2;
        ans.push_back(rem);
        n = n / 2;
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin>>s;
    if(palindrome(s))
    {
        cout<<"YES\n";
        return;
    }
    map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        mpp[s[i]]++;
    }
    for(auto it:mpp)
    {
        if(it.second%2)
        {
            cout<<"NO\n";
            return;
        }
    }
    // every char has even frequency.
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[n-i-1])
        {
            // no problem
        }
        else
        {
            int j=n-i-1;
            while(j>i && s[j]!=s[i])
            {
                j-=2;
            }
            if(i==j || j<0)
            {
                cout<<"NO\n";
                return;
            }
            swap(s[n-i-1],s[j]);
        }
    }
    // cout<<s<<"\n";
    if(palindrome(s))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
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
    return 0;
}

// aaadeadceaac
// a
// abbbab
// abbbba