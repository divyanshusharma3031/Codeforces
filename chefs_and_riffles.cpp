#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> arr, int n, int k)
{
    int x = log2(n) - 1;
    vector<vector<int>> dp;
    dp.push_back(arr);
    while (x)
    {
        vector<int> aux1;
        vector<int> aux2;
        int i = 0;
        while (i < n)
        {
            if (i % 2)
            {
                aux1.push_back(arr[i]);
            }
            else
            {
                aux2.push_back(arr[i]);
            }
            i++;
        }
        i = 0;
        int j = 0;
        while (j < aux2.size())
        {
            arr[i] = aux2[j];
            i++;
            j++;
        }
        j = 0;
        while (j < aux1.size())
        {
            arr[i] = aux1[j];
            j++;
            i++;
        }
        dp.push_back(arr);
        x--;
    }
    vector<int> ans = dp[((k) % dp.size())];
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        solve(arr, n, k);
    }
}