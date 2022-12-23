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
void solve(ll n,ll m,ll l)
{
    if(n==0)
    {
        cout<<m<<"\n";
        return;
    }
    ll f=n+l-1;
    ll left=m%f;
    f=left;
    while(left>=l)
    {
        left=left%f;
        f=left;
    }
    cout<<left<<"\n";
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
        ll m;
        cin>>m;
        ll l;
        cin>>l;
        solve(n,m,l);
    }
}