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
 
// C function for extended Euclidean Algorithm (used to
// find modular inverse.
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
 
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x % m + m) % m;
}
 
// Function to compute a/b under modulo m
int modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1)
        return -1;
    else
        return (inv * a) % m;
}
 
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
 
    vector<string> arr;
 
    map<int, int> one;
    map<int, int> two;
    map<int, int> three;
    map<int, int> four;
    map<int, int> five;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
        if (s.size() == 1)
        {
            one[s[0] - '0']++;
        }
        else if (s.size() == 2)
        {
            int sum = 0;
            for (auto it : s)
            {
                sum = sum + it - '0';
            }
            two[sum]++;
        }
        else if (s.size() == 3)
        {
            int sum = 0;
            for (auto it : s)
            {
                sum = sum + it - '0';
            }
            three[sum]++;
        }
        else if (s.size() == 4)
        {
            int sum = 0;
            for (auto it : s)
            {
                sum = sum + it - '0';
            }
            four[sum]++;
        }
        else
        {
            int sum = 0;
            for (auto it : s)
            {
                sum = sum + it - '0';
            }
            five[sum]++;
        }
    }
    int ans = 0;
    for (auto s : arr)
    {
        if (s.size() == 3)
        {
            ans = ans + one[(s[2] - '0') + (s[1] - '0') - (s[0] - '0')];
            ans = ans + one[(s[0] - '0') + (s[1] - '0') - (s[2] - '0')];
            ans = ans + three[(s[2] - '0') + (s[1] - '0') + (s[0] - '0')];
        }
        else if (s.size() == 1)
        {
            ans = ans + one[s[0] - '0'];
        }
        else if (s.size() == 5)
        {
            ans = ans + one[(s[4] - '0') + (s[3] - '0') + (s[2] - '0') - (s[1] - '0') - (s[0] - '0')];
            ans = ans + one[(s[0] - '0') + (s[1] - '0') + (s[2] - '0') - (s[3] - '0') - (s[4] - '0')];
            ans = ans + three[(s[4] - '0') + (s[3] - '0') + (s[2] - '0') + (s[1] - '0') - (s[0] - '0')];
            ans = ans + three[(s[0] - '0') + (s[1] - '0') + (s[2] - '0') + (s[3] - '0') - (s[4] - '0')];
            ans = ans + five[(s[4] - '0') + (s[3] - '0') + (s[2] - '0') + (s[1] - '0') + (s[0] - '0')];
        }
        else if (s.size() == 2)
        {
            ans = ans + two[(s[0] - '0') + (s[1] - '0')];
        }
        else
        {
            ans = ans + two[(s[3] - '0') + (s[2] - '0') + (s[1] - '0') - (s[0] - '0')];
            ans=ans+two[(s[0]-'0')+(s[1]-'0')+(s[2]-'0')-(s[3]-'0')];
            ans = ans + four[(s[0] - '0') + (s[1] - '0') + (s[2] - '0') + (s[3] - '0')];
        }
    }
    cout << ans << "\n";
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