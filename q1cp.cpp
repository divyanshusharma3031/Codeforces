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
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    if (s1 == s2)
    {
        cout << "=\n";
        return;
    }
    if (s1 == "M")
    {
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == 'S')
            {
                cout << ">\n";
                return;
            }
            else if (s2[i] == 'L')
            {
                cout << "<\n";
                return;
            }
        }
    }
    else if (s2 == "M")
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == 'S')
            {
                cout << "<\n";
                return;
            }
            else if (s1[i] == 'L')
            {
                cout << ">\n";
                return;
            }
        }
    }
    int i = 0;
    while (s1[i] == 'X')
    {
        i++;
    }
    int j = 0;
    while (s2[j] == 'X')
    {
        j++;
    }
    if (s1[i] != s2[j])
    {
        if(s1[i]=='L')
        {
            cout<<">\n";
        }
        else
        {
            cout<<"<\n";
        }
    }
    else if (s1[i] == 'S')
    {
        if (i > j)
        {
            cout << "<\n";
        }
        else
        {
            cout << ">\n";
        }
    }
    else
    {
        if (i < j)
        {
            cout << "<\n";
        }
        else
        {
            cout << ">\n";
        }
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