#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

typedef vector<ll> vi;

void reverse(int lo, int hi, vector<int> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}

bool palindrome(string s)
{
    int i = 0;
    int n = s.length() - 1;
    if (n == 0)
    {
        return false;
    }
    while (i <= n)
    {
        if (s[i] != s[n])
        {
            return false;
        }

        i++;
        n--;
    }
    return true;
}

void solve()
{
int n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
        a[i] += i + 1;
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for (int i = 0; i < k; i++) ans -= a[i];
    for (int i = 0; i < k; i++) {
        ans += n;
        ans -= i;
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
        solve();
    }
}