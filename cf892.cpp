// template taken from Striver_79
// Remember you were also a novice when you started
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure.
// The goal is to solve problems most efficiently not just barely
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
void myerase(ordered_set &t, int v)
{
    int rank = t.order_of_key(v);                     // Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); // Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
int power(long long x, unsigned int y, int p = 1e9 + 7)
{
    int res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
vector<vector<int>> merge(vector<vector<int>> &intervals,vector<vector<int>> &pos)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    pair<int, int> p;
    p.first = intervals[0][0];
    p.second = intervals[0][1];
    vector<vector<int>> ans;
    vector<int> v;
    v.push_back(0);
    vector<int> newv;
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= p.second)
        {
            v.push_back(i);
            p.second = max(p.second, intervals[i][1]);
        }
        else
        {
            vector<int> x;
            pos.push_back(v);
            v=newv;
            v.push_back(i);
            x.push_back(p.first);
            x.push_back(p.second);
            ans.push_back(x);
            p.first = intervals[i][0];
            p.second = intervals[i][1];
        }
    }
    vector<int> x;
    x.push_back(p.first);
    x.push_back(p.second);
    pos.push_back(v);
    ans.push_back(x);
    return ans;
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    vector<vector<int>> arr; // l ,r ,a ,b.
    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        int l;
        int r;
        cin >> l >> r >> a >> b;
        arr.push_back({l,b,a,r});
    }
    int q;
    cin>>q;
    vector<int> queries(q,0);
    for(int i=0;i<q;i++)
    {
        cin>>queries[i];
    }
    sort(arr.begin(),arr.end());
    vector<vector<int>> pos;
    vector<vector<int>> intervals=merge(arr,pos);
    n=intervals.size();
    for(int i=0;i<queries.size();i++)
    {
        int x=queries[i];
        int lo=0;
        int hi=n-1;
        int idx=-1;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(x>intervals[mid][1])
            {
                lo=mid+1;
            }
            else if(x<intervals[mid][0])
            {
                hi=mid-1;
            }
            else
            {
                idx=mid;
                break;
            }
        }
        if(idx!=-1)
        {
            cout<<intervals[idx][1]<<" ";
        }
        else
        {
            cout<<x<<" ";
        }
    }
    cout<<"\n";
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}