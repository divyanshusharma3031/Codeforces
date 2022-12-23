#include<bits/stdc++.h>
using namespace std;
void solve(int n,int k,int x)
{
    if(k<x)
    {
        cout<<"-1"<<"\n";
        return;
    }
    if(x==0)
    {
        int i=0;
        while(i<n)
        {
            cout<<"1"<<" ";
            i++;
        }
        cout<<"\n";
        return;
    }
    int i=0;
    int j=0;
    while(i<n)
    {
        cout<<j<<" ";
        j=(j+1)%x;
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
    while(t--)
    {
        int n;
        int k;
        int x;
        cin>>n>>k>>x;
        solve(n,k,x);
    }
}