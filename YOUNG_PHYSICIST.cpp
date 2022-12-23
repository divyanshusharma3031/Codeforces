#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
void solve(vector<ll> &x, vector<ll> &y, vector<ll> &z)
{
    ll s1 = 0;
    ll s2 = 0;
    ll s3 = 0;
    for (int i = 0; i < x.size(); i++)
    {
        s1 += x[i];
        s2 += y[i];
        s3 += z[i];
    }
    if (s1 == 0 && s2 == 0 && s3 == 0)
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    vector<ll> x;
    vector<ll> y;
    vector<ll> z;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll a;
        ll b;
        ll c;
        cin >> a >> b >> c;
        x.push_back(a);
        y.push_back(b);
        z.push_back(c);
    }
    solve(x, y, z);
    return 0;
}