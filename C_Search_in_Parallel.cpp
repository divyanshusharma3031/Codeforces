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
    ll s1;
    ll s2;
    cin >> s1 >> s2;
    vi arr(n, 0);
    priority_queue<pi> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pq.push({arr[i], i + 1});
    }
    // first wala s1 seconds
    // secibd wala s2 seconds
    vector<int> v;
    vector<int> v2;
    while (!pq.empty())
    {
        int time1 = (v.size() + 1) * s1;
        int time2 = (v2.size() + 1) * s2;
        if (time1 <= time2)
        {
            v.push_back(pq.top().second);
        }
        else
        {
            v2.push_back(pq.top().second);
        }
        pq.pop();
    }
    cout << v.size() << " ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << "\n";
    cout << v2.size() << " ";
    for (auto it : v2)
    {
        cout << it << " ";
    }
    cout << "\n";
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