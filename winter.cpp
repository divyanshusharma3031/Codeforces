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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    ll q;
    cin >> q;
    vector<int> arr[n + 1];
    vector<int> travelled(n + 1, 0);
    while (m--)
    {
        int u;
        int v;
        cin >> u;
        cin >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    map<int, int> mpp; // 1 means it is frozen;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u;
            cin >> u;
            mpp[u] = 1;
        }
        else if (type == 2)
        {
            int t;
            cin >> t;
            while (t--)
            {
                if (mpp.size() == n)
                {
                    break;
                }
                vector<int> aux;
                for (auto it : mpp)
                {
                    if (it.second == 1 && (travelled[it.first] == 0))
                    {
                        travelled[it.first] = 1;
                        for (auto i : arr[it.first])
                        {
                            if (mpp[i] != 1)
                            {
                                aux.push_back(i);
                            }
                        }
                    }
                }
                int w = 0;
                while (w < aux.size())
                {
                    mpp[aux[w]] = 1;
                    w++;
                }
                if (mpp.size() == n)
                {
                    break;
                }
            }
        }
        else if (type == 3)
        {
            int v;
            cin >> v;
            if (mpp[v] == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}
