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
void solve(int n, vector<int> &arr, string str)
{
    int nor = 0;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'S')
        {
            s++;
        }
        else
        {
            nor++;
        }
    }
    bool b = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            b = false;
            break;
        }
    }
    if (b)
    {
        cout << "0\n";
        return;
    }
    if (s == n || n == nor)
    {
        cout << "-1\n";
        return;
    }
    int w = n - 1;
    while (w > 0 && (arr[w] >= arr[w - 1]))
    {
        w--;
    }
    char x;
    if (str[w] == 'N')
    {
        x = 'S';
    }
    else
    {
        x = 'N';
    }
    int m = 0;
    bool pos = false;
    while (m < n - 1 && (arr[m] <= arr[m + 1]))
    {
        if (str[m] == x)
        {
            pos = true;
        }
        m++;
    }
    int xd = m - 1;
    int yd = w + 1;
    int n1 = 0;
    int n2 = 0;
    int s1 = 0;
    int s2 = 0;
    int it = 0;
    if (xd != -1 && yd != n)
    {
        while (it < xd)
        {
            if (str[it] == 'N')
            {
                n1++;
            }
            else
            {
                s1++;
            }
            it++;
        }
        while (yd < n)
        {
            if (str[it] == 'N')
            {
                n2++;
            }
            else
            {
                s2++;
            }
            yd++;
        }
        if (n1 != 0 && s1 != 0 && s2 != 0 && n2 != 0)
        {
            cout << "1\n";
            return;
        }
        if (n1 == 0 && s2 == 0)
        {
            cout << "1\n";
            return;
        }
        if (n2 == 0 && s1 == 0)
        {
            cout << "1\n";
            return;
        }
    }
    if (str[m] == x || pos)
    {
        cout << "1\n";
        return;
    }
    cout << "2\n";
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
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        string s;
        cin >> s;
        solve(n, arr, s);
    }
}
