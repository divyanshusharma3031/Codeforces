#include<bits/stdc++.h>
using namespace std;
void solve(int l,int r,int k)
{
    int c=r-l+1;
    if(c==k)
    {
        cout<<"YES"<<"\n";
        return;
    }
    if(l==r)
    {
        if(l==1)
        {
            cout<<"NO"<<'\n';
            return;
        }
        cout<<"YES"<<"\n";
        return;
    }
    if(l%2==0)
    {
        int x=r-l;
        if(x%2)
        {
            x++;
        }
        int e=x/2;
        int o=x-e;
        if(o<=k)
        {
            cout<<"YES"<<'\n';
            return;
        }
        cout<<"NO"<<'\n';
        return;
    }
    else
    {
        l++;
        int x=r-l;
        if(x%2)
        {
            x++;
        }
        int e=x/2;
        int o=x-e+1;
        if(o<=k)
        {
            cout<<"YES"<<'\n';
            return;
        }
        cout<<"NO"<<'\n';
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        int l;
        int r;
        int k;
        cin>>l>>r>>k;
        solve(l,r,k);
    }
}