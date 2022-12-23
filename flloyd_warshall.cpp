#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long arr[4][4] = {{0, 3, INT_MAX, 7},
                           {8, 0, 2, INT_MAX},
                           {5, INT_MAX, 0, 1},
                           {2, INT_MAX, INT_MAX, 0}};
    int n = 4;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}