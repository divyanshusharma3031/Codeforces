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
void Rotate(vector<int> &arr, int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    return;
}
void rotate(vector<int> &nums, int k,int i)
{
    int n = nums.size();
    k = k % n;
    Rotate(nums, i, n - 1);
    Rotate(nums, i, n - k - 1);
    Rotate(nums, n - k, n - 1);
    return;
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    vi arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> v = arr;
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int ele = v[i];
        int idx = i;
        int j=i;
        for (j = i; j < n; j++)
        {
            if (ele == arr[j])
            {
                idx = j;
                break;
            }
        }
        rotate(arr,j-i,i);
        if(i!=j)
            ans.push_back({i+1,n,j-i});
    }
    cout<<ans.size()<<"\n";
    for(auto it:ans)
    {
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
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