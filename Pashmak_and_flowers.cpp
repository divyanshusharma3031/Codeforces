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
    vi arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int x=0;
    int mn=arr[0];
    int y=0;
    int mx=arr[n-1];
    for(int i=0;i<n;i++)
    {
        if(mn==arr[i])
        {
            x++;
        }
        if(mx==arr[i])
        {
            y++;
        }
    }
    if(mn==mx)
    {
        cout<<mx-mn<<" ";
        cout<<x*(x-1)/2<<"\n";
        return;
    }
    int ans=x*y;
    cout<<mx-mn<<" ";
    cout<<ans<<"\n";
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}