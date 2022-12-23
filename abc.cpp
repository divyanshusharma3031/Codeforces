#include<bits/stdc++.h>
using namespace std;
void solve(string s)
{
    if(s.length()==1)
    {
        cout<<"YES"<<"\n";
        return;
    }
    if(s.length()<=2)
    {
        int z=0;
        int c=0;
        for(int i=0;i<2;i++)
        {
            if(s[i]=='0')
            {
                z++;
            }
            else
            {
                c++;
            }
        }
        if(z==c)
        {cout<<"YES"<<"\n";}
        else
        {
            cout<<"NO"<<"\n";
        }
        return;
    }
    cout<<"NO"<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(s);
    }
}