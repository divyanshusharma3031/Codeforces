#include<bits/stdc++.h>
using namespace std;
void solve(string s)
{
    sort(s.begin(),s.end());
    cout<<s<<"\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin>>s;
        solve(s);
    }
}