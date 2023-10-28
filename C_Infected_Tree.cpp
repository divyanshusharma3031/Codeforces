// template taken from Striver_79
// Remember you were also a novice when you started
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure.
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
int dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &nodes)
{
    if(vis[node])
    {
        return 0;
    }
    vis[node]=1;
    int c=1;
    for(auto it:adj[node])
    {
        c=c+dfs(it,adj,vis,nodes);
    }
    return nodes[node]=c;
}
void Solve(int node,int parent,vector<int> adj[],vector<int> &vis,vector<int> &nodes,int &ans,int count)
{
    
    if(vis[node])
    {
        return;
    }
    vis[node]=1;
    vector<int> v;
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            v.push_back(nodes[it]);
        }
    }
    if(v.size()<2)
    {
        v.push_back(0);
    }
    for(int i=0;i<v.size();i++)
    {
        ans=max(count+v[i],ans);
    }
    int j=1;
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            Solve(it,node,adj,vis,nodes,ans,count+v[j]);
            j--;
        }
    }
    return ;
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n-1; i++)
    {
        int x;
        cin >> x;
        int y;
        cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n+1,0);
    vector<int> nodes(n+1,0);
    dfs(1,adj,vis,nodes);
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        nodes[i]--;
    }
    int ans=0;
    int count=0;
    Solve(1,-1,adj,vis,nodes,ans,count);
    cout<<ans<<"\n";
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}