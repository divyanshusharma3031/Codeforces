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
    ll n;
    cin >> n;
    ll m;
    cin>>m;
    string s;
    cin>>s;
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            c++;
        }
    }
    if(c==n)
    {
        cout<<n*m<<"\n";
        return;
    }
    int x=n-c;
    int o=m*(n-c);//total no. of ones//total sum
    if(o%2)
    {
        cout<<"0\n";
        return;
    }
    int f=o/2;
    int i=0;
    int j=m*n;
    int cnt=0;
    int ans=0;
    while(1)
    {
        if((cnt+x)<f)
        {
            cnt+=x;
        }
        else
        {
            break;
        }
    }
    cout<<f<<"\n";
    while(i<j)
    {
       cnt=cnt+(s[i]-'0');
       if(f==cnt)
       {
        ans++;
       }
       else if(f<cnt)
       {
        break;
       }
       i=(i+1)%n;
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