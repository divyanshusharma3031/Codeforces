#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            int t = -nums[i];
            int j = i + 1;
            int k = n - 1;
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                while (j < k)
                {

                    int s = nums[j] + nums[k];
                    if (s == t)
                    {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        while (j < k && nums[j] == nums[j + 1])
                        {
                            j++;
                        }
                        while (k > j && nums[k] == nums[k - 1])
                        {
                            k--;
                        }
                        j++;
                        k--;
                    }
                    else if (s < t)
                    {
                        j++;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}