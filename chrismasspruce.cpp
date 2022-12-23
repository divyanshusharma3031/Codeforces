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
    vector<int> adj[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int x;
        cin>>x;
        adj[x].push_back(i+1);
    }
    map<int,int> leafs;
    // cout<<"start\n";
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==0)
        {
            leafs[i]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int c=0;
        if(leafs[i])
        {
            continue;
        }
        // cout<<i<<" ";
        for(auto it:adj[i])
        {
            // cout<<it<<" ";
            if(leafs[it])
            {
                c++;
            }
        }
        if(c>=3)
        {

        }
        else
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}