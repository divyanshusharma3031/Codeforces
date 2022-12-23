#include<bits/stdc++.h>
using namespace std;
void solve(int n,int k)
{
    if(k>n)
    {
        cout<<"-1"<<"\n";
        return;
    }
    if(n==1)
    {
        cout<<"1"<<"\n";
        return;
    }
    if(k==1)
    {
        cout<<"-1"<<"\n";
        return;
    }
    int x=k-2;
    int y=x+2;
    int w=y;
    while(y<=n)
    {
        cout<<y<<" ";
        y++;
    }
    int i=w-1;
    while(i>=1)
    {
        cout<<i<<" ";
        i--;
    }
    cout<<"\n";
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
        int k;
        cin>>k;
        solve(n,k);
    }
}