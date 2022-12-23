#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

typedef vector<ll> vi;

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
int converttomin(string &s)
{
    int hour=stoi(s.substr(0,2));
    int min=stoi(s.substr(3,2));
    return hour*60+min;
}
string converttostring(int x)
{
    int h=x/60;
    
    int m=x%60;
    string s="";
    if(h>=10)
    {
        s=s+to_string(h);
        s+=":";
    }
    else
    {
        s+="0";
        s+=to_string(h);
        s+=":";
    }

    if(m>=10)
    {
        s=s+to_string(m);
    }
    else
    {
        s+="0";
        s+=to_string(m);
    }
    return s;
}
void solve()
{
    string s;
    cin>>s;
    ll n;
    cin>>n;
    int x=converttomin(s);
    bool f=true;
    int ans=0;
    while(f || converttostring(x)!=s)
    {
        string temp=converttostring(x);
        // cout<<temp<<"\n";
        if(palindrome(temp))
        {
            ans++;
        }
        f=false;
        x=(x+n)%1440;
    }
    cout<<ans<<"\n";
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