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
    int neg=0;
    int nonneg=0;
    vector<int> v;
    vector<int> aux;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<=0)
        {
            v.push_back(arr[i]);
            neg++;
        }
        else
        {
            aux.push_back(arr[i]);

        }
    }
    if(neg==0)
    {
        cout<<"1\n";
        return;
    }
    //atleast the length will be neg now just add positive numbers to the sequence
    if(neg==n)
    {
        cout<<neg<<"\n";
    }
    else
    {
        sort(v.begin(),v.end());
        int mn=INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            mn=min(mn,abs(v[i]-v[i-1]));
        }
        // cout<<mn<<"\n";
        for(auto it:aux)
        {
            if(mn>=it)
            {
                // cout<<it<<"\n";
                neg++;
                break;
            }
        }
        cout<<neg<<"\n";
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