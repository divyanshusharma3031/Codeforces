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

void solve(string s,int n)
{
    ll i=0;
    ll cnt=0;
    while(i<n-1)
    {
        if((s[i]=='(') || (s[i]==')' && s[i+1]==')'))
        {
            i+=2;
        }
        else
        {
            ll j=i+1;
            while(j<n && s[j]!=')')
            {
                j++;
            }
            if(j==n)
            {
                break;
            }
            i=j+1;
        }
        cnt++;
    }
    cout<<cnt<<" "<<n-i<<"\n";
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