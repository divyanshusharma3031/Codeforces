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

void solve(string s, int n)
{
    int z = 0;
    int o = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            z++;
        }
        if (s[i] == '1')
        {
            o++;
        }
    }
    if (z == o)
    {
        cout << "YES\n";
        cout << 1 << " " << s.length() << "\n";
        return;
    }
    if ((z + o) % 2)
    {
        cout << "NO\n";
        return;
    }
    int x = (s.length()) / 2;
    int reqlength = 0;
    if (z > o)
    {
        reqlength = z - x;
    }
    else
    {
        reqlength = o - x;
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            c++;
        }
        else
        {
            c--;
        }
        if(c==reqlength)
        {
            cout<<"YES\n";
            cout<<1<<" "<<i+1<<"\n";
            return;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            c++;
        }
        else
        {
            c--;
        }
        if(c==reqlength)
        {
            cout<<"YES\n";
            cout<<1<<" "<<i+1<<"\n";
            return;
        }
    }
    cout << "NO\n";
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
        cin >> s;
        solve(s, n);
    }
}