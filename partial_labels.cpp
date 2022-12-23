#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int i = 0;
        int n = s.length();
        vector<vector<int>> v;
        vector<int> start(26, 0 - 1);
        vector<int> end(26, -1);
        for (int i = 0; i < s.length(); i++)
        {
            if (start[s[i] - 'a'] == -1)
            {
                start[s[i] - 'a'] = i;
            }
            else
            {
                end[s[i] - 'a'] = i;
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (start[s[i] - 'a'] != -1)
            {
                v.push_back({start[s[i] - 'a'], end[s[i] - 'a']});
            }
        }
        sort(v.begin(), v.end());
        // cout<<v.size();
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i][0]<<" "<<v[i][1]<<'\n';
        }
        // pair<int, int> p;
        // p.first = v[0][0];
        // p.second = v[0][1];
        // vector<vector<int>> ans;
        // for (int i = 1; i < v.size(); i++)
        // {
        //     if (v[i][0] <= p.second)
        //     {
        //         p.second = max(p.second, v[i][1]);
        //     }
        //     else
        //     {
        //         vector<int> x;
        //         x.push_back(p.first);
        //         x.push_back(p.second);
        //         p.first = v[i][0];
        //         p.second = v[i][1];
        //         ans.push_back(x);
        //     }
        // }
        // ans.push_back({p.first, p.second});
        vector<int> a;
        // for (int i = 0; i < ans.size(); i++)
        // {
        //     a.push_back((ans[i][1] - ans[i][0]) + 1);
        // }
        return a;
    }
};
int main()
{
    Solution obj;
    obj.partitionLabels("ababcbacadefegdehijhklij");
}