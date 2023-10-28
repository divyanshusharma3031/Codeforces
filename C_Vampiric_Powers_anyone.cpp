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

struct TrieNode
{
    int value;
    TrieNode *child[2];
    TrieNode()
    {
        this->value = 0;
        this->child[0] = this->child[1] = NULL;
    }
};

class Solution
{
public:
    void insert(TrieNode *root, int pre_xor)
    {
        TrieNode *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            bool curr = pre_xor & (1 << i);
            if (temp->child[curr] == NULL)
            {
                temp->child[curr] = new TrieNode();
            }
            temp = temp->child[curr];
        }
        temp->value = pre_xor;
    }
    int query(TrieNode *root, int pre_xor)
    {
        TrieNode *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            bool curr = pre_xor & (1 << i);
            if (temp->child[1 - curr] != NULL)
            {
                temp = temp->child[1 - curr];
            }
            else if (temp->child[curr] != NULL)
            {
                temp = temp->child[curr];
            }
        }
        return pre_xor ^ (temp->value);
    }
    int maxSubarrayXOR(int N, vector<int> &arr)
    {
        TrieNode *root = new TrieNode();
        insert(root, 0);
        int result = INT_MIN, pre_xor = 0;
        for (int i = 0; i < N; i++)
        {
            pre_xor = pre_xor ^ arr[i];
            insert(root, pre_xor);
            result = max(result, query(root, pre_xor));
        }
        return result;
    }
};

void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution obj;
    int ans=obj.maxSubarrayXOR(n,arr);
    cout<<ans<<"\n";
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