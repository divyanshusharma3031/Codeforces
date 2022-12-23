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


void solve()
{
    ll l1;
    ll l2;
    ll r1;
    ll r2;
    cin>>l1>>r1>>l2>>r2;
    if(l1==r1 && r1==l2 && l2==r2)
    {
        cout<<l1<<"\n";
        return;
    }
    else
    {
        ll x1=min(l1,r1);
        ll y1=min(l2,r2);
        for(int i=l1;i<=r1;i++)
        {
            if(i>=l2 && i<=r2)
            {
                cout<<i<<"\n";
                return;
            }
        }
        cout<<l1+l2<<"\n";
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
        solve();
    }
}