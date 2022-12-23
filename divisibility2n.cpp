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
    vi arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s=0;
    for(int i=0;i<n;i++)
    {
        while(arr[i]>0 && arr[i]%2==0)
        {
            s++;
            arr[i]=arr[i]/2;
        }
        if(s>=n)
        {
            cout<<"0\n";
            return;
        }
    }
    int rem=n-s;
    int c=0;
    int y=1;
    while(y*2<=n)
    {
        y=y*2;
    }
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        int wy=i;
        int cu=0;
        while(wy>1 && wy%2==0)
        {
            cu++;
            wy=wy/2;
        }
        v.push_back(cu);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++)
    {
        c+=1;
        rem=rem-v[i];
        if(rem<=0)
        {
            cout<<c<<"\n";
            return;
        }
    }
    cout<<"-1\n";
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