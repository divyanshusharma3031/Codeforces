#include<bits/stdc++.h>
using namespace std;
void solve(int a,int b,int c)
{
    if(a==b && b==c)
    {
        cout<<"YES"<<'\n';
        return;
    }
    else if((a+c)%(2*b)==0)
    {
        cout<<"YES"<<'\n';
        return ;
    }
    else if(((2*b-a)%c)==0 && ((2*b-a)>0))
    {
        cout<<"YES"<<'\n';
    }
    else if((2*b-c)%a==0 && ((2*b-c)>0))
    {
        cout<<"YES"<<'\n';
    }
    else
    {
        cout<<"NO"<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        int b;
        int c;
        cin>>a;
        cin>>b;
        cin>>c;
        solve(a,b,c);
    }
}