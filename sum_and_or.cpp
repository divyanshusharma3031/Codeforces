#include<bits/stdc++.h>
using namespace std;
void solve(int x,int n)
{
    int ans=-1;
    if(x==1)
    {
        cout<<n<<'\n';
        return;
    }
    if((n%x)==0)
    {
        cout<<n/x<<"\n";
        return;
    }
    int y=log2(x);
    int z=x-pow(2,y);
    int w=pow(2,y)+1;
    if(w!=0 && n%w==z)
    {
        ans=n/w+1;
    }
    if(z!=0 && n%z==w)
    {
        if(ans!=-1)
        {
            ans=min(ans,n/z+1);
        }
        else
        {
            ans=n/z+1;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin>>x;
        int n;
        cin>>n;
        solve(x,n);   
    }
}