#include <bits/stdc++.h>
using namespace std;
void solve(int n, int k, string s)
{
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            s[i]=s[j];
            k--;
            if (k < 0)
            {
                cout << "NO"
                     << "\n";
                return;
            }
        }
        i++;
        j--;
    }
    if (k == 0)
    {
        cout << "YES"
             << "\n";
        return;
    }
    i = 0;
    j = n - 1;
    if (k == 1)
    {
        if (n % 2)
        {
            cout << "YES"
                 << "\n";
            return;
        }
    }
    while (i <= j)
    {
        if (i == j)
        {
            if (k == 0)
            {
                cout << "YES"
                     << "\n";
                return;
            }
            k = k - 1;
        }
        else if (s[i] == s[j])
        {
            k = k - 2;
            if (k == 1)
            {
                if (n % 2)
                {
                    cout << "YES"
                         << "\n";
                    return;
                }
            }
            if (k == 0)
            {
                cout << "YES"
                     << "\n";
                return;
            }
            if (k < 0)
            {
                cout << "NO"
                     << "\n";
                return;
            }
        }
        i++;
        j--;
    }
    if (k == 0)
    {
        cout << "YES"
             << "\n";
        return;
    }
    else
    {
        cout << "NO"
             << "\n";
        return;
    }
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
        int k;
        string str;
        cin >> n;
        cin >> k;
        cin >> str;
        solve(n, k, str);
    }
}