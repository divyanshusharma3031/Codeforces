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
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        string s;
        cin>>s;
        v.push_back(s);
    }
    vector<int> ans(n,0);
    for(int i=0;i<n;i++)
    {
        int ele=arr[i];
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j]=='D')
            {
                ele=(ele+1)%10;
            }
            else
            {
                ele=ele-1;
                if(ele<0)
                {
                    ele=9;
                }
            }
        }
        ans[i]=ele;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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