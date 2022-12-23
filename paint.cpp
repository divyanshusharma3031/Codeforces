#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
int paint(long long arr[], int n)
{
    if (n == 1)
    {
        return 1;
    }
    int x = arr[0];
    int y = arr[1];
    for (int i = 0; i < n; i += 2)
    {
        x = gcd(x, arr[i]);
    }
    for (int i = 1; i < n; i += 2)
    {
        y = gcd(y, arr[i]);
    }
    if (x != y)
    {
        if (x != 1)
        {
            vector<int> v(n);
            if (v[0] % x == 0)
            {
                v[0] = 0;
            }
            else
            {
                v[0] = 1;
            }
            int i;
            for (i = 1; i < n; i++)
            {
                if (v[i] % x == 0)
                {
                    v[i] = 0;
                }
                else
                {
                    v[i] = 1;
                }
                if (v[i] == v[i - 1])
                {
                    break;
                }
                if (i == n)
                {
                    return x;
                }
            }
        }
        if (y != 1)
        {
            vector<int> v(n);
            if (v[0] % y == 0)
            {
                v[0] = 0;
            }
            else
            {
                v[0] = 1;
            }
            int i;
            for (i = 1; i < n; i++)
            {
                if (v[i] % y == 0)
                {
                    v[i] = 0;
                }
                else
                {
                    v[i] = 1;
                }
                if (v[i] == v[i - 1])
                {
                    break;
                }
            }
            if (i == n)
            {
                return y;
            }
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << paint(arr, n) << "\n";
    }
    return 0;
}