#include <bits/stdc++.h>
using namespace std;
void solve(int arr[], int n)
{
    vector<int> ans(n + 1, -1);
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        while (arr[i] > n )
        {
            arr[i] = (arr[i] / 2);
        }
        while(ans[arr[i]]==1)
        {
            arr[i]=arr[i]/2;
            if(arr[i]==0)
            {
                break;
            }
        }
        ans[arr[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == -1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
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