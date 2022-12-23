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
    vi arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    map<int,vector<int>> mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]].push_back(i+1);
    }
    if(mpp[arr[0]].size()==n)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    int x=mpp.size();
    vector<vector<int>> matrix;
    for(auto it:mpp)
    {
        vector<int> v;
        for(auto y:it.second)
        {
            v.push_back(y);
        }
        matrix.push_back(v);
    }
    for(int i=0;i<matrix.size()-1;i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            cout<<matrix[(i+1)%x][0]<<" "<<matrix[i][j]<<"\n";
            // cout<<matrix[i][j]<<" ";
        }
    }
    for(int i=1;i<matrix[matrix.size()-1].size();i++)
    {
        cout<<matrix[0][0]<<" "<<matrix[matrix.size()-1][i]<<"\n";
    }
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