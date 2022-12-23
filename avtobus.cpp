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
    long long n;
    cin>>n;

    if(n%2 || n<4)
    {
        cout<<"-1\n";
        return;
    }

    if(n%4==0 && n%6==0)
    {
        cout<<n/6<<" "<<n/4<<"\n";
        return;
    }

    ll y=0;

    ll mn=-1;

    while((n-6*y)%4!=0)
    {
        y++;
    }

    ll mx=(n-6*y)/4+y;

    ll x=0;

    while((n-4*x)%6!=0)
    {
        x++;
    }

    mn=(n-4*x)/6+x;

    cout<<mn<<" "<<mx<<"\n";
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