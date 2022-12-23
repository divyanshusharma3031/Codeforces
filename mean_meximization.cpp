#include <bits/stdc++.h>
using namespace std;
void solve(int arr[], int n)
{
    int mx = -1;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (mx < arr[i])
        {
            mx = max(mx, arr[i]);
            idx = i;
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (i!=idx)
        {
            s += arr[i];
        }
    }
    float x = (float(s)) / (n - 1);
    float y=float(mx)+x;
    printf("%f",y);
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