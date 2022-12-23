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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll x;
    cin>>x;
    string s;
    cin>>s;
    while(x--)
    {
        string ans;
        for(int i=0;i<s.length();)
        {
            if(s[i]=='B' && s[i+1]=='G')
            {
                ans+='G';
                ans+='B';
                i+=2;
            }
            else
            {
                ans+=s[i];
                i++;
            }
        }
        s=ans;
    }
    cout<<s<<"\n";
}