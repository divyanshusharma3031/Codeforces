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
    vi arr(n, 0);
    bool b=false;
    map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
        if(mpp[arr[i]]>2)
        {
            b=true;
        }
    }
    if(b)
    {
        cout<<"NO\n";
        return;
    }
    vi p(n,0);
    vi q(n,0);
    set<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i])==s.end())
        {
            p[i]=arr[i];
        }
        else
        {
            q[i]=arr[i];
        }
        s.insert(arr[i]);
    }
    set<int> s1;
    set<int> s2;
    for(int i=1;i<=n;i++)
    {
        s1.insert(i);
        s2.insert(i);
    }
    for(auto it:p)
    {
        s1.erase(it);
    }
    for(auto it:q)
    {
        s2.erase(it);
    }
    for(int i=0;i<n;i++)
    {
        if(p[i]==0)
        {
            auto it=s1.lower_bound(q[i]);
            if(*it==q[i])
            {
                p[i]=q[i];
                s1.erase(it);
            }
            else
            {
                if(it==s1.begin())
                {
                    cout<<"NO\n";
                    return;
                }
                it--;
                p[i]=*it;
                s1.erase(it);
            }
            
        }
        else if(q[i]==0)
        {
            auto it=s2.lower_bound(p[i]);
            if(*it==p[i])
            {
                q[i]=p[i];
                s2.erase(it);
            }
            else
            {
                if(it==s2.begin())
                {
                    cout<<"NO\n";
                    return;
                }
                it--;
                q[i]=*it;
                s2.erase(it);
            }
        }
    }
    cout<<"YES\n";
    for(auto it:p)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    for(auto it:q)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
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