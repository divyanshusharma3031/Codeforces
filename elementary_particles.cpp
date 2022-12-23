#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int n)
{
    unordered_map<int, vector<int>> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]].push_back(i);
    }
    int ans = 0;
    for (auto i = mpp.begin(); i != mpp.end(); i++)
    {
        vector<int> a = i->second;
        for (int j = 1; j < a.size(); j++)
        {
            ans = max(ans, n + a[j - 1] - a[j]);
        }
    }
    if (ans == 0)
    {
        return -1;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr, n) << '\n';
    }
}