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

void dfs(int node, vector<pair<int, int>> adj[], vector<int> &vis, int &mn, int x, int target)
{
    vector<int> level(target + 1, 1e9);
    deque<int> q;
    q.push_back(1);
    level[1]=0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop_front();
        for (auto i : adj[x])
        {
            int v = i.first;
            int wt;
            if (i.second == (-1))
            {
                wt = 1;
            }
            else
            {
                wt = 0;
            }
            if ((level[x] + wt) < level[v])
            {
                level[v] = level[x] + wt;
                if (wt == 1)
                {
                    q.push_back(v);
                }
                else
                {
                    q.push_front(v);
                }
            }
        }
    }
cout << level[target] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<pair<int, int>> adj[n + 1];
    while (m--)
    {
        int u;

        int v;

        cin >> u;

        cin >> v;
        if (u == v)
        {
            continue;
        }
        adj[u].push_back({v, 1});
        adj[v].push_back({u, -1});
    }
    int mn = INT_MAX;
    vector<int> vis(n + 1, 0);
    int x = 0;
    dfs(1, adj, vis, mn, x, n);
}
