#include<bits/stdc++.h>
using namespace std;
void solve(string s)
{
    string ans="YES";
    int n=s.length();
    int i=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='N')
        {
           int idx=i;
            i=(i+1)%n;
            do
            {
                if(s[i]=='E')
                {
                    i=(i+1)%n;
                }
                else
                {
                    break;
                }
                /* code */
            } while (idx!=i);
            if(idx==i)
            {
                cout<<"NO"<<"\n";
                return;
            }
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        solve(s);
    }
}