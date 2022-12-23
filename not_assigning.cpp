#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (arr[i].size() > 2)
        {
            cout << "-1"
                 << "\n";
                 return;
        }
    }

    map<pair<int, int>, int> vis;
    int pre = -1;
    for (int i = 1; i <= n; i++)
    {
        int m = arr[i].size();
        for (int j = 0; j < m; j++)
        {
            if (vis[{i, arr[i][j]}] == 1 || vis[{arr[i][j], i}] == 1)
            {
                continue;
            }
            if (pre == -1)
            {
                cout << "2"
                     << " ";
                pre = 2;
            }
            else
            {
                cout << "3"
                     << " ";
                pre = -1;
            }
            vis[{i, arr[i][j]}] = 1;
            vis[{arr[i][j], i}] = 1;
        }
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr[n + 1];
        for (int i = 0; i < n - 1; i++)
        {
            int u;
            int v;
            cin >> u;
            cin >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        solve(arr, n);
    }
}