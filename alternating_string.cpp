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

void solve(string s,ll n)
{
    int z=0;
    int o=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            z++;
        }
        else
        {
            o++;
        }
    }
    if(z==o)
    {
        cout<<z+o<<"\n";
        return;
    }
    cout<<2*min(z,o)+1<<"\n";
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
        string s;
        cin>>s;
        solve(s,n);
    }
}