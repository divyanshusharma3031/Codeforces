// template taken from Striver_79
// Remember you were also a novice when you started
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill And unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it And enjoy it, you will succeed for sure.
// The goal is to solve problems most efficiently not just barely
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
typedef long long ll;
#define MAX 100000
#define bitscount 32

// Array to store bit-wise
// prefix count
int prefix_count[bitscount][MAX];

// Function to find the prefix sum
void findPrefixCount(vector<int> &arr, int n)
{

    // Loop for each bit
    for (int i = 0; i < bitscount; i++)
    {
        // Loop to find prefix count
        prefix_count[i][0] = ((arr[0] >> i) & 1);
        for (int j = 1; j < n; j++)
        {
            prefix_count[i][j] = ((arr[j] >> i) & 1);
            prefix_count[i][j] += prefix_count[i][j - 1];
        }
    }
}

// Function to answer query
int rangeOr(int l, int r)
{

    // To store the answer
    int ans = 0;

    // Loop for each bit
    for (int i = 0; i < bitscount; i++)
    {
        // To store the number of variables
        // with ith bit set
        int x;
        if (l == 0)
            x = prefix_count[i][r];
        else
            x = prefix_count[i][r] - prefix_count[i][l - 1];

        // Condition for ith bit
        // of answer to be set
        if (x != 0)
            ans = (ans | (1 << i));
    }

    return ans;
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n, 0);
    vector<int> pref(n + 1, 0);
    memset(prefix_count,0,sizeof(prefix_count));
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s =(s+ arr[i])%mod;
        pref[i + 1] =s;
    }
    findPrefixCount(arr,n);
    int i = 0;
    int j = 0;
    int And = arr[j];
    int ans=0;
    while (j < n)
    {
        And = And&arr[j];
        if (And < k)
        {
            // we cant find And > k further so just rest
            i = j;
            And = arr[j];
        }
        if (And >= k)
        {
            ans = max(ans, rangeOr(i,j) + (pref[j + 1] - pref[i]+mod)%mod);
        }
        j++;
    }
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