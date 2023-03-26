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
void go(int offset, int k,vector<char> &people,vector<char> &combination,vector<vector<char>> &ans)
{
    if (k == 0)
    {
        ans.push_back(combination);
        return;
    }
    for (int i = offset; i <= people.size() - k; ++i)
    {
        combination.push_back(people[i]);
        go(i + 1, k - 1,people,combination,ans);
        combination.pop_back();
    }
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    int k;
    cin >> k;
    string a;
    string b;
    cin >> a >> b;
    set<char> s;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            s.insert(a[i]);
        }
    }
    int c = s.size();
    if (c <= k)
    {
        int ans = n * (n + 1) / 2;
        cout << ans << "\n";
        return;
    }
    vector<char> v;
    for (auto it : s)
    {
        v.push_back(it);
    }
    vector<vector<char>> ans;
    vector<char> gen;
    go(0,k,v,gen,ans);
    int an=-1e9;
    for(auto it:ans)
    {
        set<char> temp;
        for(auto x:it)
        {
            temp.insert(x);
        }
        int cnt=0;
        int ax=0;
        for(int i=0;i<=n;i++)
        {
            if(i==n)
            {
                ax=ax+cnt*(cnt+1)/2;
                break;
            }
            if(a[i]==b[i] || temp.find(a[i])!=temp.end())
            {
                cnt++;
            }
            else
            {
                
                ax=ax+cnt*(cnt+1)/2;
                cnt=0;
            }
        }
        an=max(an,ax);
    }
    cout<<an<<"\n";
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