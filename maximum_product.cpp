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
    vector<int> positive;
    vector<int> negative;
    vector<int> zero;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        if(x>=0)
        {
            positive.push_back(x);
        }
        else if(x<0)
        {
            negative.push_back(x);
        }
    }
    if(n==5)
    {
        int ans=1;
        for(int i=0;i<5;i++)
        {
            ans=ans*arr[i];
        }
        cout<<ans<<"\n";
        return;
    }
    sort(positive.begin(),positive.end(),greater<int>());
    sort(negative.begin(),negative.end());
    int p=positive.size();
    int ns=negative.size();
    int ans=LONG_MIN;
    if(positive.size()>=5)
    {
        int x=1;
        for(int i=0;i<5;i++)
        {
            x=x*positive[i];
        }
        if(negative.size()>=2)
        {
            x=max(x,positive[0]*positive[1]*positive[2]*negative[0]*negative[1]);
        }
        if(negative.size()>=4)
        {
            x=max(x,positive[0]*negative[0]*negative[1]*negative[2]*negative[3]);
        }
        cout<<x<<"\n";
    }
    else
    {
        if(p==0)
        {
            int x=1;
            reverse(negative.begin(),negative.end());
            for(int i=0;i<5;i++)
            {
                x=x*negative[i];
            }
            cout<<x<<"\n";
            return;
        }   
        else if(p==1 || p==2)
        {
            int x=positive[0];
            for(int i=0;i<4;i++)
            {
                x=x*negative[i];
            }
            cout<<x<<"\n";
            return;
        }
        else if(p==3 || p==4)
        {
            int x=1;
            for(int i=0;i<3;i++)
            {
                x=x*positive[i];
            }
            x=x*negative[0]*negative[1];
            if(negative.size()>=4)
            {
                int y=positive[0];
                for(int i=0;i<4;i++)
                {
                    y=y*negative[i];
                }
                x=max(x,y);
            }
            cout<<x<<"\n";
            return;
        }
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

