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
void solve(vi &arr,vi &ans,int i,int s,int cur,bool &b,vi &fans)
{
    if(b)
    {
        return;
    }
    if(cur==s)
    {
        b=true;
        fans=ans;
        return;
    }
    int n=arr.size();
    if(i==n)
    {
        return;
    }
    if(cur>s)
    {
        return;
    }
    ans.push_back(1);
    solve(arr,ans,i+1,s,cur+1*arr[i],b,fans);
    ans.pop_back();
    ans.push_back(0);
    solve(arr,ans,i+1,s,cur,b,fans);
    ans.pop_back();
    ans.push_back(-1);
    solve(arr,ans,i+1,s,cur-1*arr[i],b,fans);
    ans.pop_back();
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    ll k;
    cin>>k;
    ll s;
    cin>>s;
    vi arr;
    map<int,int> mpp;
    mpp[1]++;
    mpp[-1]++;
    mpp[0]++;
    for(int i=0;i<n;i++)
    {
        int x=(s%k+k)%k;
        if(!mpp[x])
        {
            cout<<"-2\n";
            return;
        }
        arr.push_back(x);
        s=(s-x)/k;
    }
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}