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

void solve(vector<int> &x, vector<int> &y, int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(x[i], y[i]));
    }
    sort(v.begin(), v.end());
    vector<int> aux;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        aux.push_back(v[i].second);
    }

    int ans = 1;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (aux[i] >= aux[j])
                dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
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
        ll n;
        cin >> n;
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            x.push_back(a);
        }
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            y.push_back(a);
        }
        solve(x, y, n);
    }
}
