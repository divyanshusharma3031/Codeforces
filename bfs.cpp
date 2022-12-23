vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    queue<int> q;
    int n = V;
    vector<int> vis(V + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                ans.push_back(x);
                for (int j = 0; j < adj[x].size(); j++)
                {
                    if (vis[adj[i][j]] == 0)
                    {
                        vis[adj[i][j]] = 1;
                        q.push(adj[i][j]);
                    }
                }
            }
        }
    }
    return ans;
}