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
void solve(ll n,ll k,string s)
{
    vector<int> one(n,0);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            sum++;
            one[i]=sum;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            
        }
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
        ll k;
        cin >> k;
        string s;
        cin>>s;
        solve(n,k,s);
    }
}