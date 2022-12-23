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
    vi a(n,0);
    vi b(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    if(n==1)
    {
        cout<<a[0]+b[0]<<"\n";
        return;
    }
    vector<int> ans(n,0);

    sort(a.begin(),a.end());
    
    sort(b.begin(),b.end());
    for(int i=0;i<n/2;i++)
    {
        ans[i]=a[i]+b[i];
    }
    int x=n-1;
    for(int j=(n)/2;j<n;j++)
    {
        ans[j]=a[j]+b[x];
        x--;
    }
    sort(ans.begin(),ans.end());
    cout<<ans[n/2]<<"\n";
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

// 5
// 10 4 93 5 16
// 4 34 62 6 26

// 4 5 10 16 93
// 4 6 26 34 62

// 4 5 16 10 93
// 4 6 34 62 26

// 