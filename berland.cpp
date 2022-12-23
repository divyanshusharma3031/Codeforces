#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
void solve(int arr[], int n, string s)
{
    int z = 0;
    vector<pair<int, int>> zero;
    vector<pair<int, int>> one;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zero.push_back({arr[i], i});
            z++;
        }
        else
        {
            one.push_back({arr[i], i});
        }
    }
    sort(one.begin(), one.end());
    sort(zero.begin(), zero.end());
    int j=0;
    for (int i = 0; i < z; i++)
    {
        zero[i].first = i + 1;
        j++;
    }
    for (int i = 0; i < one.size(); i++)
    {
        one[i].first = j + 1;
        j++;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < z; i++)
    {
        ans.push_back(zero[i]);
    }
    for (int i = 0; i < one.size(); i++)
    {
        ans.push_back(one[i]);
    }
    sort(ans.begin(), ans.end(), compare);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i].first << " ";
    }
    cout << "\n";
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
        string s;
        cin >> s;
        solve(arr, n, s); //
    }
}