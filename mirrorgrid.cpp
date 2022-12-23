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
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<string> s;
    for (int i = 0; i < n; i++)
    {
        string s1;
        cin>>s1;
        s.push_back(s1);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j]=(s[i][j]-'0');
        }
    }
    int N=n;
    vector<vector<int>> arr = matrix;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - j][N - 1 - i];
            arr[N - 1 - j][N - 1 - i] = temp;
        }
    }

    // Second rotation
    // with respect to middle row
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - i][j];
            arr[N - 1 - i][j] = temp;
        }
    }

    vector<vector<int>> matrix2 = matrix;
    for (int i = 0; i < n; i++)
    {
        reverse(matrix2[i].begin(), matrix2[i].end());
    }
    vector<vector<int>> matrix3 = arr;
    reverse(matrix3.begin(), matrix3.end());
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != matrix[i][j])
            {
                c++;
            }
        }
    }
    int c2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix2[i][j] != matrix[i][j])
            {
                c2++;
            }
        }
    }
    int c3 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix3[i][j] != matrix[i][j])
            {
                c3++;
            }
        }
    }
    cout<<min({c,c2,c3})<<"\n";
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