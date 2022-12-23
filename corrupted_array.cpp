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
    vi b(n+2,0);
    for(int i=0;i<n+2;i++)
    {
        cin>>b[i];
    }
    
    sort(b.begin(),b.end());
    
    // the sum will exist at n+1th pos or at n+2-th position

    // assuming it at n+2
    int ts=b[n+1];
    map<int,int> mpp1;
    int s=0;
    for(int i=0;i<=n;i++)
    {
        s+=b[i];
        mpp1[s]++;
    }
    int idx=-1;
    for(int i=0;i<=n;i++)
    {
        int temps=s;
        temps=temps-b[i];
        if(ts==temps)
        {
            idx=i;
            break;
        }
    }
    if(idx!=-1)
    {
        for(int i=0;i<=n;i++)
        {
            if(i==idx)
            {

            }
            else
            {
                cout<<b[i]<<" ";
            }
        }
        cout<<"\n";
        return;
    }
    ts=b[n];
    s=0;
    for(int i=0;i<n;i++)
    {
        s=s+b[i];
    }
    if(s==ts)
    {
        for(int i=0;i<n;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    cout<<"-1\n";
    return;
}
int32_t main()
{
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