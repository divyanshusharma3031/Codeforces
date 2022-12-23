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
vector<int> primeFactors(int n)
{
    vector<int> ans;
    while (n % 2 == 0)
    {
        ans.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            ans.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        ans.push_back(n);
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    vi ans=primeFactors(n);
    if(ans.size()<3)
    {
        cout<<"NO\n";
        return;
    }
    vector<int> v;
    int x=ans.size();
    int a=1;
    map<int,int> mpp;
    mpp[1]++;
    for(int i=0;i<x;i++)
    {
        a=a*ans[i];
        if(mpp[a]!=0)
        {

        }
        else
        {
            v.push_back(a);
             mpp[a]++;
            if(v.size()==2)
            {
                i++;
                a=1;
                while(i<x)
                {
                    a=a*ans[i];
                    i++;
                }
                if(mpp[a]==0 )
                {
                    v.push_back(a);
                }
                else
                {
                    
                }
                break;
            }
           
            a=1;
        }
    }
    if(v.size()<3)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
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