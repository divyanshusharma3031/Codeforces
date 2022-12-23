#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
    ll a;
    ll b;
    cin>>a>>b;
    string s;
    cin>>s;
    int n=s.length();
    int lo=a;
    int hi=0;
    int c=0;
    for(int j=0;j<n;j++)
    {
        if(s[j]=='0')
        {
            c++;
        }
    }
    if(c==n)
    {
        cout<<"0\n";
        return;
    }
    int ans=0;
    int i=0;
    while(i<n && s[i]=='0')
    {
        i++;
    }
    ans=a;
    c=0;
    for(;i<n;i++)
    {
        if(s[i]=='0')
        {
            c++;
        }
        else
        {
            ans=min(ans+a,ans+b*c);
            c=0;
        }
    }
    cout<<ans<<"\n";
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