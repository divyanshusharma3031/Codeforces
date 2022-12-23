#include<bits/stdc++.h>
using namespace std;
void solve(int a[],int b[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i])
        {
            int temp=a[i];
            a[i]=b[i];
            b[i]=temp;
        }
    }
    int x=-1;
    int y=-1;
    for(int i=0;i<n;i++)
    {
        x=max(x,a[i]);
        y=max(y,b[i]);
    }
    int z=x*y;
    cout<<z<<"\n";
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
        int a[n];
        int b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        solve(a,b,n);
    }
}