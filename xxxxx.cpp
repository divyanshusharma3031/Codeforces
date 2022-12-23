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
    
    int x;

    cin>>x;

    vi arr(n,0);
    

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    if(n==1)
    {
        if(arr[0]%x==0)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<1<<"\n";
        }
        return;
    }
    if(x==1)
    {
        cout<<"-1\n";
        return;
    }
    
    vector<int> pref(n,0);
    
    pref[0]=arr[0];
    
    for(int i=1;i<n;i++)
    {
        pref[i]=pref[i-1]+arr[i];
    }


    int fnznd=-1;

    for(int i=0;i<n;i++)
    {
        if(pref[i]%x)
        {
            fnznd=i;
            break;
        }
    }
    if(fnznd==-1)
    {
        cout<<"-1\n";
        return;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(pref[i]%x)
        {
            ans=max(ans,i+1);
        }
        else
        {
            ans=max(ans,i-fnznd);
        }
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