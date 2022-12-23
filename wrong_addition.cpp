#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(string a, string s)
{
    ll n = a.length();
    ll m = s.length();
    reverse(s.begin(), s.end());
    reverse(a.begin(), a.end());
    string b;
    ll i = 0;
    ll j = 0;
    while (i < m && j < n)
    {
        int a1 = s[i] - 48;
        int a2 = a[j] - 48;
        if (a2 > a1)
        {
            if ((i + 1) >= m)
            {
                cout << "-1\n";
                return;
            }
            a1 = (s[i + 1] - 48) * 10 + (s[i] - 48);
            if((a1-a2)<0)
            {
                cout<<"-1\n";
                return;
            }
            // cout<<a1<<" "<<a2<<"\n";
            i++;
            // cout<<a1-a2<<" ";
            if((a1-a2)>=10)
            {
                cout<<"-1\n";
                return;
            }
            b += to_string(a1 - a2);
        }
        else
        {
            b += to_string(a1 - a2);
        }
        i++;
        j++;
    }
    if(j!=n)
    {
        cout<<"-1\n";
        return;
    }
    while(i<m)
    {
        b+=s[i];
        i++;
    }
    reverse(b.begin(),b.end());
    i=0;
    while(i<b.length() && b[i]=='0')
    {
        i++;
    }
    if(i==n)
    {
        cout<<"0\n";
    }
    while(i<b.length())
    {
        cout<<b[i];
        i++;
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string s;
        cin >> a;
        cin >> s;
        solve(a, s);
    }
}