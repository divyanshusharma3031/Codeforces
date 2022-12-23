#include <bits/stdc++.h>
using namespace std;
long long solve(vector<long long> arr, int n, int k)
{
    if (k == 1)
    {
        long long globalMaxSum = nums[0], currMaxSum = nums[0];
        for (int ind = 1; ind < nums.size(); ind++)
        {
            currMaxSum = max(currMaxSum + nums[ind], nums[ind]);
            globalMaxSum = max(globalMaxSum, currMaxSum);
        }
        return globalMaxSum
    }
    vector<long long> nums = arr;
    int i = 0;
    while (i < n)
    {
        nums.push_back(arr[i]);
        i++;
    }
    long long total = nums[0];
    for (int ind = 1; ind < n; ind++)
    {
        total += arr[ind];
    }
    long long globalMaxSum = nums[0], currMaxSum = nums[0];
    for (int ind = 1; ind < nums.size(); ind++)
    {
        currMaxSum = max(currMaxSum + nums[ind], nums[ind]);
        globalMaxSum = max(globalMaxSum, currMaxSum);
    }
    return max(globalMaxSum, globalMaxSum + total * (k - 2));
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<long long> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr, n, k) << '\n';
    }
    return 0;
}
