#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Reverse(int lo, int hi, vector<int> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}

void solve(vector<ll> arr, int n)
{
    vector<ll> v1;
    vector<ll> v2;
    for (int i = 0; i < n; i++)
    {
        if ((i % 2) == 0)
        {
            v1.push_back(abs(arr[i]));
        }
        else
        {
            v2.push_back(abs(arr[i]));
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());
    ll x = v2[0];
    ll y = v1[0];
    if (x > y)
    {
        v2[0] = y;
        v1[0] = x;
    }
    ll s1 = 0;
    ll s2 = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        s1 += v1[i];
    }

    for (int i = 0; i < v2.size(); i++)
    {
        s2 += v2[i];
    }

    cout << (s1 - s2) << "\n";
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
        vector<ll> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}
