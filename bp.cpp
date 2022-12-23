#include <bits/stdc++.h>
using namespace std;
bool possible(int n, vector<int> &arr, int &idx)
{
    int i = 0;
    int j = arr.size() - 1;
    if(arr[j]<=n)
    {
        return false;
    }
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        // if (arr[mid] == n)
        // {
        //     idx = mid;
        //     return true;
        // }
        if (arr[mid] > n)
        {
            idx = mid;
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    // cout << n << " " << idx << "\n";
    if (idx == -1)
    {
        return false;
    }
    return true;
}
int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> ans;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (ans.size() == 0)
            {
                ans.push_back(x);
                continue;
            }
            else
            {
                int idx = -1;
                if (possible(x, ans, idx))
                {
                    ans[idx] = x;
                }
                else
                {
                    ans.push_back(x);
                    // sort(ans.begin(),ans.end());
                }
            }
        }
        cout<<ans.size()<<" ";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
