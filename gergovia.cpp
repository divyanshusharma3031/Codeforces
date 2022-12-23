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

void solve(ll n)
{
    vector<ll> arr(n+1,0);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long ans=0;
    long long total=arr[0];
    for(int i=1;i<n;i++)
    {
        ans=ans+abs(total);
        total=total+arr[i];
    }
    cout<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        ll n;
        cin>>n;
        if(n==0)
        {
            break;
        }
        solve(n);
    }
}