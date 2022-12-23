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
    int n;
    cin >> n;

    int q;

    cin >> q;


    map<ll,ll> mppx;

    map<ll,ll> mppy;

    set<ll> s1;

    set<ll> s2;

    for(ll i=1;i<=n;i++)
    {
        s1.insert(i);
        s2.insert(i);
    }

    while (q)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            ll x;

            ll y;

            cin >> x >> y;
            mppx[x]++;
            if(mppx[x]==1)
            {
                s1.erase(x);
            }
            mppy[y]++;
            if(mppy[y]==1)
            {
                s2.erase(y);
            }
        }
        else if (t == 2)
        {
            ll x;
            ll y;
            cin >> x >> y;
            mppx[x]--;
            if(mppx[x]==0)
            {
                s1.insert(x);
            }
            mppy[y]--;
            if(mppy[y]==0)
            {
                s2.insert(y);
            }
        }
        else
        {
            ll x1;

            ll y1;

            ll x2;

            ll y2;

            cin >> x1 >> y1 >> x2 >> y2;

            bool b=false;

            if((s1.lower_bound(x1)==s1.end()) || (*(s1.lower_bound(x1)))>x2)
            {
                b=true;
            }
            if((s2.lower_bound(y1)==s2.end() )|| (*(s2.lower_bound(y1)))>y2)
            {
                b=true;
            }
            if(b)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
        q--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    solve();
}