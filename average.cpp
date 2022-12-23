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
void solve(ll n, ll m, ll x)
{
    ll mx = x * n;
    ll ans = 0;
    ll b=x+1;
    if(x==m)
    {
        cout<<"0\n";
        return;
    }
    for (int i = n-1; i >=1; i++)
    {
        ll w=i*b;
        float rem=(float(mx-w))/(n-i);
        // cout<<rem<<"\n";
        if(rem<=x && rem>=0)
        {
            ans=i;
            break;
        }
        else
        {
            //
        }
    }
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
        ll x, m;
        cin >> m >> x;
        solve(n, m, x);
    }
}