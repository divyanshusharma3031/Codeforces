#include <bits/stdc++.h>
using namespace std;
void solve(int arr[],int n)
{
    int hash[n] = {0};
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        while (arr[i] > n || hash[(arr[i] / 2) - 1] == 0)
        {
            arr[i] /= 2;
        }
        if (hash[arr[i] - 1] == 0)
        {
            hash[arr[i] - 1]++;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (hash[i] != 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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