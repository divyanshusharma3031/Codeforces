#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n)
{
    long long s=0;
    int x=INT_MAX;
    int idx=0;
    for(int i=0;i<n;i++)
    {
        s+=(arr[i]);
        if(x>arr[i])
        {
            idx=i;
        }
        x=min(arr[i],x);
    }
    float f=log2(s);
    if(f==int(f))
    {
        cout<<"0"<<'\n';
        return;
    }
    int p=log2(s);
    int np=pow(2,p+1);
    int diff=np-s;
    cout<<"1\n";
    cout<<"1 "<<diff/x+1<<'\n';
    cout<<idx+1<<'\n';
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
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        solve(arr,n);
    }
}