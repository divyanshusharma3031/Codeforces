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
    if(n==1)
    {
        if(s[0]=='1')
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"0\n";
        }
        return;
    }
    int len=INT_MIN;
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            len=max(len,c);
            c=0;
        }
        else
        {
            c++;
        }
    }
    len=max(len,c);
    if(len==0)
    {
        cout<<0<<"\n";
    }
    else if(len==1)
    {
        cout<<1<<"\n";
    }
    else
    {
        cout<<2<<"\n";
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
        ll n;
        cin >> n;
        string s;
        cin>>s;
        solve(s,n);
    }
}