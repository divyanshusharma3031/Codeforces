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
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        ll m;
        cin >> m;
        vi arr(m, 0);
        for (int j = 0; j < m; j++)
        {
            cin >> arr[j];
        }
        matrix.push_back(arr);
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(),v.end());
    map<int, int> mpp;
    for (int i = 0; i < v.size(); i++)
    {
        mpp[v[i]] = i;
    }
    int blocks = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < matrix[i].size(); j++)
        {
            if ((mpp[matrix[i][j]] - 1) != mpp[matrix[i][j - 1]])
            {
                blocks++;
            }
        }
        // cout<<blocks<<" ";
    }
    cout<<blocks-n<<" "<<blocks-1<<"\n";
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}