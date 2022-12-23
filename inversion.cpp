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
    for(int i=0;i<n-1;i++)
    {
        if((arr[i]==1 && arr[i+1]==2) || (arr[i]==0 && arr[i+1]==2) || (arr[i]==1 && arr[i+1]==0) || (arr[i]==1 && arr[i+1]==1) || (arr[i]==3 && arr[i+1]==0) || (arr[i]==2 && arr[i+1]==0))
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    
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
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}