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
int countsubarrays(vector<int> &arr,int i,int j)
{
    int c=0;
    for(;i<=j;i++)
    {
        int s=0;
        for(int x=i;x<=j;x++)
        {
            s=s+arr[x];
            if(s>0)
            {
                c++;
            }
            if(s==0)
            {
                return -1;
            }
        }
    }
    return c;
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    int total = n * (n + 1) / 2; // the total subarrays
    // k subarrays with positive sum
    // size*(size+1)=k;
    vi arr(n, 2);
    if (total == k)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << -arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int sz = 0;
    int i = 0;
    while (sz * (sz + 1) < 2 * k)
    {
        sz++;
        i++;
    }
    if ((2 * k) == (sz * (sz + 1)))
    {
        for (; i < n; i++)
        {
            arr[i] = -1000;
        }
        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }
        cout << "\n";
        return;
    }
    i--;
    for(int j=1;j<=1000;j++)
    {
        arr[i]=-j;
        if(countsubarrays(arr,0,i)==k)
        {
            for(int x=i+1;x<n;x++)
            {
                arr[x]=-1000;
            }
            break;
        }
    }
    for(auto it:arr)
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