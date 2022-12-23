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
    ll c;
    cin>>c;
    ll q;
    cin>>q;
    vi l(c+1,0);
    vi r(c+1,0);
    string a;
    cin>>a;
    string s="1";
    s+=a;
    // cout<<s<<"\n";
    for(int i=1;i<=c;i++)
    {
        cin>>l[i];
        cin>>r[i];
    }
    vector<int> len(c+1,0);
    len[0]=s.length()-1;
    for(int i=1;i<=c;i++)
    {
        len[i]=len[i-1]+r[i]-l[i]+1;
    }
    for(int i=0;i<q;i++)
    {
        int k;
        cin>>k;
        int j=c;
        while(j>0)
        {
            if(len[j-1]>=k)
            {
                j--;
            }
            else{
                k=k-len[j-1];
                k=l[j]+k-1;
                j--;
            }
        }
        cout<<s[k]<<"\n";
    }
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