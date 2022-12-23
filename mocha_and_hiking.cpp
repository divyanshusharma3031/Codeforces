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
void dfs(int node,vector<int> adj[],bool &b,vector<int> &v,int arr[],int n)
{
    if(b)
    {
        return;
    }
    
    if(arr[node])
    {
        return;
    }
    v.push_back(node);
    arr[node]=1;
    if(v.size()==n)
    {
        for(auto it:v)
        {
            cout<<it<<" ";
        }
        cout<<"\n";
        b=true;
    }
    for(auto it:adj[node])
    {
        dfs(it,adj,b,v,arr,n);
    }
    arr[node]=0;
    v.pop_back();
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    // n+1 villages
    // 2n-1 directed roads
    // n-1 roads are from i to i+1
    // 
    vector<int> adj[n+2];
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        arr.push_back(c);
    }
    for(int i=1;i<=n-1;i++)
    {
        adj[i].push_back(i+1);
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==0)
        {
            adj[i+1].push_back(n+1);
        }
        else
        {
            adj[n+1].push_back(i+1);
        }
    }
    bool b=false;
    for(int i=1;i<=n+1;i++)
    {
        vector<int> v;
        int arr[n+2];
        memset(arr,0,sizeof(arr));
        dfs(i,adj,b,v,arr,n+1);
        if(b)
        {
            break;
        }
    }
    if(!b)
    {
        cout<<"-1\n";
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