#include <bits/stdc++.h>
using namespace std;
void solve(long long n)
{
    if ((n % 2) == 0)
    {
        long long ans = 0;
        for (long long i = 1; i <= n; i++)
        {
            if (i % 2)
            {
                ans += i ^ (i + 1);
            }
            else
            {
                ans += i ^ (i - 1);
            }
        }
         cout << ans << "\n";
        return;
    }
    else
    {
        long long ans = 0;
        for (long long i = 1; i <= n - 1;i++)
        {
            if (i % 2)
            {
                ans += i ^ (i + 1);
            }
            else
            {
                ans += i ^ (i - 1);
            }
        }
        cout<<ans<<"\n";
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
        long long n;
        cin >> n;
        solve(n);
    }
}