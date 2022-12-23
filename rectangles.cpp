#include <bits/stdc++.h>
using namespace std;
void solve(int l1, int l2, int l3)
{
    if ((l1 == l2) && (l2==l3))
    {
        if (l1 % 2)
        {
            cout << "NO" << '\n';
            return;
        }
        else
        {
            cout << "YES"<<'\n';
            return;
        }
    }
    unordered_map<int, int> mpp;
    mpp[l1]++;
    mpp[l2]++;
    mpp[l3]++;
    bool b = false;
    for (auto i = mpp.begin(); i != mpp.end(); i++)
    {
        if (i->second == 2)
        {
            b = true;
        }
    }
    if (b)
    {
        for (auto i = mpp.begin(); i != mpp.end(); i++)
        {
            if (i->second == 1)
            {
                if ((i->first) % 2)
                {
                    cout << "NO" << '\n';
                    return;
                }
                else
                {
                    cout << "Yes" << '\n';
                }
            }
        }
        return;
    }
    int x = max(l1, max(l2, l3));
    if (x == l1)
    {
        if (x == l2 + l3)
        {
            cout << "YES" << '\n';
            return;
        }
        else
        {
            cout << "NO" << '\n';
            return;
        }
    }
    if (x == l2)
    {
        if (x == l1 + l3)
        {
            cout << "YES" << '\n';
            return;
        }
        else
        {
            cout << "NO" << '\n';
            return;
        }
    }
    if (x == l3)
    {
        if (x == l2 + l1)
        {
            cout << "YES" << '\n';
            return;
        }
        else
        {
            cout << "NO" << '\n';
            return;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l1;
        int l2;
        int l3;
        cin >> l1 >> l2 >> l3;
        solve(l1, l2, l3);
    }
}