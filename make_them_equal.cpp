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

void solve(vector<ll> &arr,ll n)
{
    int odd=0;
    int even=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    if(even==n || odd==n)
    {
        cout<<0<<"\n";
        return;
    }
    if(odd%2)
    {
        cout<<even<<"\n";
    }
    else
    {
        cout<<min(odd/2,even)<<"\n";
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
        ll n;
        cin >> n;
        vector<ll> arr(n,0);
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
    }
}