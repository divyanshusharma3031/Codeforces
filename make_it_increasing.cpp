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
    vector<int> b(n, 0);
    ll mn = 1e18;
    for (int i = 0; i < n; i++)
    {
        ll c = 0;
        ll ele = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if ((arr[j] > ele) || (ele == 0))
            {
                c++;
                ele = arr[j];
            }
            else
            {
                ll rem = ele / arr[j] + 1;
                c += ele / arr[j] + 1;
                ele = arr[j] * rem;
            }
            // cout << ele << " ";
        }
        ele = 0;
        // cout<<ele<<" ";
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > ele || ele == 0)
            {
                c++;
                ele = arr[j];
            }
            else
            {
                ll rem = ele / arr[j] + 1;
                c += rem;
                ele = arr[j] * rem;
            }
            // cout << ele << " ";
        }
        mn = min(mn, c);
    }
    cout << mn << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);
}