#include <bits/stdc++.h>
using namespace std;
void solve(string s, int n, int x)
{
    int dp[n + 1] = {0};
    dp[n] = 0;
    int c = 0;
    vector<int> r(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        if (s[i] == '0')
        {
            c++;
            if (c == x)
            {
                dp[i] += 1;
                c = 0;
            }
        }
        else
        {
            c = 0;
        }
    }
    c = 0;
    r[n - 1] = 0;
    if (s[n - 1] == '0')
    {
        c++;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = c;
        if (s[i] == '0')
        {
            c++;
        }
        else
        {
            c = 0;
        }
    }
    c=0;
    int ans=dp[0];
    c=0;
    int vac=0;
    for(int i=0;i<n;i++)
    {
        r[i]=r[i]+1;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            if(r[i]>=(i+x-1-c))
            {
                ans=max(ans,vac+dp[i+x-c]+1);
            }
            c=0;
        }
        else
        {
            c++;
            if(c==x)
            {
                vac++;
                c=0;
            }
        }
    }
    cout<<ans<<"\n";
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
        int x;
        cin >> x;
        string s;
        cin >> s;
        solve(s, n, x);
    }
}
// 5 7 8 10 20 30 
// 30 5 7 8 10 19 20 22 30 50 
// 50 28 30 5 7 8 10 19 20 22 30 35 40 45 50 
// 50 28 30 5 7 8 10 19 20 22 30 35 40 45 50