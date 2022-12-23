#include<bits/stdc++.h>
using namespace std;
void solve(int n,int k)
{
    float y=((float)n)/2;
    if(ceil(y)<k)
    {
        cout<<"-1"<<"\n";
        return ;
    }
    int x=0;
    bool b=true;
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==x && b && c<k)
            {
                cout<<"R";
                c++;
            }
            else
            {
                cout<<".";
            }
        }
        cout<<"\n";
        if(b)
        {
            x=x+2;
        }
        b=!b;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        solve(n,k);
    }
}