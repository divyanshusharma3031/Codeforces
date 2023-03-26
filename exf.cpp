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
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    vi a(n,0);
    ll m;
    cin>>m;
    vi b(m,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    //only one such pair exist it is given 
    // Approach 1:Kind of bruteforce //O(nlogn)
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int diff=1e18;
    int x=-1;
    int y=-1;
    for(int i=0;i<n;i++)
    {
        auto it=upper_bound(b.begin(),b.end(),a[i]);//number greater than a[i];
        if(it==b.end())
        {
            it--;
            int idx=it-b.begin();
            int d1=abs(a[i]-b[idx]);
            if(diff>d1)
            {
                d1=diff;
                x=a[i];
                y=b[idx];
            }
        }
        else
        {
            it--;//number less than or equal to it
            int idx=it-b.begin();
            int d1=abs(a[i]-b[idx]);
            idx++;
            int d2=abs(a[i]-b[idx]);
            int mndiff=min(d1,d2);
            if(diff>mndiff)
            {
                diff=mndiff;
                if(mndiff==d1)
                {
                    x=a[i];
                    y=b[idx-1];
                }
                else
                {
                    x=a[i];
                    y=b[idx];
                }
            }
        }
    }
    cout<<x<<" "<<y<<"\n";
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