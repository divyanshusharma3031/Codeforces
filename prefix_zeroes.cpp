#include <bits/stdc++.h>
using namespace std;
void solve(int n, int k, string s)
{
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        arr[i] = s[i] - 48;
    }
    if ((10 - arr[0]) > k)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                break;
            }
            ans++;
        }
        cout << ans << "\n";
        return;
    }
    int x = 10 - arr[0];
    vector<int> aux(n, 0);
    int i = 0;

    int ans = 0;
    int prev=INT_MAX;
    while (i < n)
    {
        int mn = 10 - arr[i];
        int pre = mn;
        // while (mn <= k)
        // {
        //     pre = mn;
        //     mn += 10;
        // }
        // if (pre == mn)
        // {
        //     break;
        // }
        int y=(k-mn);
        int x=y/10;
        pre=mn+10*x;
        if(pre>prev)
        {
            break;
        }
        k = pre;
        prev=pre;
        arr[i] = 0;
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            break;
        }
        ans++;
    }
    cout << ans << "\n";
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
        string s;
        cin >> n >> k;
        cin >> s;
        solve(n, k, s);
    }
}