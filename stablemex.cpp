#include <bits/stdc++.h>
using namespace std;

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
void solve(vector<ll> &arr, ll n)
{
    set<int> s;
    int c = 0;
    for (int i = 0; i <n; i++)
    {
        s.insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (c == 0)
        {
            c++;
        }
        s.erase(arr[i]);
    }
    sort(arr.begin(), arr.end());
    ll mex = *(s.begin());
    if (mex == 1)
    {
        cout << "-1\n";
        return;
    }
    if (mex == 0)
    {
        cout << arr[0] - 1 << "\n";
        return;
    }
    int reqlength = mex - 1;
    int i = 0;
    set<int> s2;
    for (int i = 0; i < n; i++)
    {
        s2.insert(arr[i]);
    }
    vector<int> aux;
    for (auto it : s2)
    {
        aux.push_back(it);
    }
    int k = 1;
    int ans = 0;
    for (int i=0; i < aux.size(); i++)
    {
        if ((aux[i-1]+1)!=aux[i])
        {
            if (k >= reqlength)
            {
                ans++;
            }
            k=1;
        }
        else
        {
            k = 1;
        }
    }
    if (k >= reqlength)
    {
        ans++;
    }
    cout << ans-1 << "\n";
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