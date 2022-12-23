#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

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
    if (n == 1)
    {
        cout << "0" << endl;
        return;
    }
    int e = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            e++;
        }
    }
    if (e <= 1)
    {
        cout << "0" << endl;
        return;
    }
    ll mn=-1;
    ll mx=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            if(mn==-1)
            {
                mn=i;
            }
            mx=i;
        }
    }
    if(mn==mx)
    {
        cout<<0<<"\n";
    }
    cout<<max(mx-mn-1,1ll)<<"\n";
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