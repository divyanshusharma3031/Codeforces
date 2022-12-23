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
map<string,int> mpp;
int minmoves(int n,int x,string s)
{
    string sub=to_string(x)+s;
    if(s.length()>=n)
    {
        return 0;
    }
    if(mpp[sub]!=0)
    {
        return mpp[sub];
    }
    int m=1e9;
    int a=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0' || s[i]=='1')
        {
            a++;
            continue;
        }
        int w=x*(s[i]-'0');
        string str=to_string(w);
        m=min(m,1+minmoves(n,w,str));
    }
    return mpp[sub]=m;
}
void solve()
{
    ll n;
    cin >> n;
    ll x;
    cin>>x;
    if(x==1 && n!=1)
    {
        cout<<"-1\n";
        return;
    }
    // after one operation length can increase atmostv by 1.
    string s=to_string(x);
    int ans=minmoves(n,x,s);
    if(ans==1e9)
    {
        cout<<"-1\n";
        return;
    }
    cout<<ans<<"\n";
}
int32_t main()
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}

    // string s=to_string(x);
    // int c=0;
    // while(s.length()!=n)
    // {
    //     string str=s;
    //     sort(str.begin(),str.end());
    //     int w=stoll(s);
    //     int a=str.size();
    //     w=w*(str[a-1]-'0');
    //     s=to_string(w);
    //     c++;
    // }