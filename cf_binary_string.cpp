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

bool sorted(string s)
{
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]>s[i+1])
        {
            return false;
        }
    }
    return true;
}
bool reversesorted(string s)
{
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]<s[i+1])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    string s;
    cin>>s;
    // cout<<s<<"\n";
    int n=s.length();
    if(sorted(s) || reversesorted(s))
    {
        cout<<0<<"\n";
        return;
    }
    int z=0;
    vector<int> pre(n,0);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            z++;
        }
        pre[i]=z;
    }
    int o=0;
    int a1=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            o++;
        }
        if(s[i]=='0')
        {
            z--;
        }
        a1=min(a1,max(o,z));
    }
    z=pre[n-1];
    cout<<z<<"\n";
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='1')
        {
            o++;
        }
        if(s[i]=='0')
        {
            z--;
        }
        a1=min(a1,max(o,z));
    }
    cout<<a1<<"\n";
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