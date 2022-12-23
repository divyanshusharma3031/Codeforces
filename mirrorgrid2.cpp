#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
void rotate90(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return;
}
void rotate180(vii &matrix)
{
    int n = matrix.size();
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
void rotate270(vii &matrix)
{
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return;
}
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

    vector<string> s;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;
        s.push_back(s1);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = (s[i][j] - '0');
        }
    }


    vector<vector<bool>> vis(n,vector<bool>(n,false));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[i][j])
            {
                continue;
            }
            int r1=i+1;
            int c1=j+1;
            int r2=c1;
            int c2=n+1-r1;
            int r3=c2;
            int c3=n+1-r2;
            int r4=c3;
            int c4=n+1-r3;
            ll l=matrix[r1-1][c1-1]+matrix[r2-1][c2-1]+matrix[r3-1][c3-1]+matrix[r4-1][c4-1];
            if(l==2)
            {
                ans+=2;
            }
            else if(l>2)
            {
                ans=ans+4-l;
            }
            else
            {
                ans+=l;
            }
            vis[r1-1][c1-1]=1;
            vis[r2-1][c2-1]=1;
            vis[r3-1][c3-1]=1;
            vis[r4-1][c4-1]=1;
        }
    }
    cout<<ans<<"\n";
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