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
bool check(int x,vpi &vect)
{
    int n=vect.size();
    ll takenSoFar = 0;
    for(ll i=n-1; i>=0; i--) {
        if(vect[i].second >=( x - takenSoFar - 1) && (vect[i].first - takenSoFar) >= 0) {
            takenSoFar++;
        }
    }
    return takenSoFar >= x;
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    vi a(n,0);
    vi b(n,0);
    vpi arr;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        arr.push_back({a[i],b[i]});
    }
    // atmost a[i] richer than him and atmost b[i] poorer than him
    // ith friend has (i+1) dollar //according to 0-based indexing.
    int lo=0;
    int hi=n;
    int ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(check(mid,arr))
        {
            ans=mid;
            // cout<<ans<<"\n";
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    cout<<ans<<"\n";
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