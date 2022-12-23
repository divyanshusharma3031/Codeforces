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
typedef vector<vector<int>> vii;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;
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
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    char c;
    cin>>c;
    string s;
    cin>>s;
    if(c=='g')
    {
        cout<<"0\n";
        return;
    }
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(c==s[i])
        {
            v.push_back(i);
        }
    }
    vector<int> arr(n,0);
    int lg=-1;
    int fg=-1;
    for(int i=0;i<n;i++)
    {
        // if()
        if(s[i]=='g')
        {
            if(fg==-1)
            {
                fg=i;
            }
            lg=i;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='g')
        {
            lg=i;
        }
        if(lg>=i)
            arr[i]=lg-i;
        else
        {
            arr[i]=n-1-i+fg+1;
        }
    }
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans=max(ans,arr[v[i]]);
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