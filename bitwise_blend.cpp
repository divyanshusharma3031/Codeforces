#include <bits/stdc++.h>
using namespace std;
void solve(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] % 2;
    }
    int z = 0;
    int o = 0;
    int idx1 = -1;
    vector<int> one;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            z++;
        }
        else
        {
            one.push_back(i + 1);
            o++;
        }
    }
    if (z == n || o == n)
    {
        cout << "-1"
             << "\n";
        return;
    }
    vector<int> ans(n, 0);
    vector<int> ans2(n, 0);
    vector<int> v1;
    vector<int> v2;
    map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        if ((i % 2) == 0)
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if ((i % 2) == 0)
        {
            ans2[i] = 1;
        }
        else
        {
            ans2[i] = 0;
        }
    }
    int mx = 0;
    int mx2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ans[i])
        {
        }
        else
        {
            v1.push_back(i + 1);
            mx++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ans2[i])
        {
        }
        else
        {
            v2.push_back(i + 1);
            mx2++;
        }
    }
    idx1=one[0];
    int prev = one[0];
    if (mx == 0)
    {
        cout << mx << "\n";
        return;
    }
    if (mx2 == 0)
    {
        cout << mx2 << "\n";
        return;
    }
    if (mx < mx2)
    {
        cout << mx << "\n";
        for (int i = 0; i < v1.size(); i++)
        {
            if ((arr[v1[i] - 1]) == 0)
            {
                cout << v1[i] << " " << (idx1) << " ";
                one.push_back(v1[i]);
            }
            else
            {
                if (v1[i] == prev)
                {
                    int w = 0;
                    while (w < v1.size() && (v1[i] == one[w] || mpp[one[w]]==1 ))
                    {
                        w++;
                    }
                    prev = v1[w];
                    mpp[prev]=1;
                    cout << v1[i] << " " << prev << "\n";
                    cout << v1[i] << " " << (prev) << " ";
                }
                 else
                {

                    cout << v1[i] << " " << (prev) << " ";
                }
            }
        }
    }
    else
    {
        cout << mx2 << "\n";
        for (int i = 0; i < v2.size(); i++)
        {
            if ((arr[v2[i] - 1]) == 0)
            {
                cout << v2[i] << " " << (idx1) << " ";
            }
            else
            {
                if (v2[i] == (prev))
                {
                    int w = 0;
                    while (w < v2.size() && (v2[i] == one[w] || mpp[one[w]]==1))
                    {
                        w++;
                    }
                    prev = v2[w];
                    mpp[prev]=1;
                    cout << v2[i] << " " << prev << "\n";
                }
                else
                {

                    cout << v2[i] << " " << (prev) << " ";
                }
            }
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}