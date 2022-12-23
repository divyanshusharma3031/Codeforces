#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void reverse(int lo, int hi, vector<int> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}

bool palindrome(string s)
{
    int i = 0;
    int n = s.length() - 1;
    if (n == 0)
    {
        return false;
    }
    while (i <= n)
    {
        if (s[i] != s[n])
        {
            return false;
        }

        i++;
        n--;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
    }
}
int knap(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n >= 0 && W >= 0 && dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if ((W - wt[n - 1]) >= 0)
    {
        return dp[n][W] = max(val[n - 1] + knap(W - wt[n - 1], wt, val, n - 1, dp), knap(W, wt, val, n - 1, dp));
    }
    return knap(W, wt, val, n - 1, dp);
}

int knap(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (n == 0)
    {

        return 0;
    }
    if (n >= 0 && W >= 0 && dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if ((W - wt[n - 1]) >= 0)
    {
        return dp[n][W] = max(val[n - 1] + knap(W - wt[n - 1], wt, val, n, dp), knap(W, wt, val, n - 1, dp));
    }
    return knap(W, wt, val, n - 1, dp);
}
int cuttingrod(int price[], int n, int W, vector<vector<int>> &dp)
{
    if (W <= 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if ((W - n) >= 0)
    {
        return dp[n][W] = max(price[n - 1] + cuttingrod(price, n, W - n, dp), cuttingrod(price, n - 1, W, dp));
    }
    return dp[n][W] = cuttingrod(price, n - 1, W, dp);
}
int cutRod(int price[], int n)
{
    // code here
    int W = n;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return cuttingrod(price, n, W, dp);
}

bool isSubsetSum(vector<int> arr, int sum)
{
    int N = arr.size();
    vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));
    int n = N;
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = true;
    }
    for (int j = 1; j <= sum; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if ((j - arr[i - 1]) >= 0)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}