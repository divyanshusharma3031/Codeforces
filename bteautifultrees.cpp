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
vector<int> constructST(vector<int> arr, int n)
{
    vector<int>tree(2*n);
    for (int i = 0; i < n; i++)
        tree[i + n] = arr[i];
    for (int i = n - 1; i > 0; i--)
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    return tree;
}

int RMQ(vector<int> &st, int n, int l, int r)
{
    int ans = INT_MAX;
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            ans = min(ans, st[l++]);
        if (r & 1)
            ans = min(ans, st[--r]);
    }
    //returns minimum of [l,r]; 
    return ans;
}
pair<int,int> possible(vi &arr,int lo,int hi,int &ans,bool &flag)
{
    int size=hi-lo;
    if(size==1)
    {
        if(arr[lo]>arr[hi])
        {
            ans++;
        }
        return {min(arr[lo],arr[hi]),max(arr[lo],arr[hi])};
    }
    int mid=(lo+hi)/2;
    pair<int,int> left=possible(arr,lo,mid,ans,flag);
    pair<int,int> right=possible(arr,mid+1,hi,ans,flag);
    if(left.first>right.second)
    {
        
        ans++;
    }
    else if(right.first>left.second)
    {
        //do nothing
    }
    else
    {
        flag=0;
    }
    return {min(left.first,right.first),max(left.second,right.second)};
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
    if(n==1)
    {
        cout<<"0\n";
        return ;
    }
    int ans=0;
    bool flag=true;
    possible(arr,0,n-1,ans,flag);
    if(!flag)
    {
        cout<<"-1\n";
        return;
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