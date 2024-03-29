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
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vii arr = matrix;
    for (int i = 0; i < n; i++)
    {
        int x = -1;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                x = j;
                for (int j = 0; j < m; j++)
                {
                    arr[i][j] = 0;
                }
                for (int i = 0; i < n; i++)
                {
                    arr[i][x] = 0;
                }
            }
        }
    }
    vii arr2=arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for(int x=0;x<m;x++)
            {
                if(arr[i][x]==1)
                {
                    arr2[i][j]=1;
                    break;
                }
            }
            for(int x=0;x<n;x++)
            {
                if(arr[x][j]==1)
                {
                    arr2[i][j]=1;
                    break;
                }
            }
        }
    }
    if(arr2==matrix)
    {
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    cout<<"NO\n";
}
 
// 1 0
// 0 0
// 0 0
// 0 0
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}