#include<bits/stdc++.h>
using namespace std;
void squarestring(string s)
{
    int n=s.length();
    if(n%2)
    {
        cout<<"NO\n";
        return;
    }
    int i=0;
    int j=n/2;
    while(j<n)
    {
        if(s[i]!=s[j])
        {
            cout<<"NO\n";
            return;
        }
        i++;
        j++;
    }
    cout<<"YES\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        squarestring(s);
    }
}