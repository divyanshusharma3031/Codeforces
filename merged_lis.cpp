#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int arr2[],int n,int m)
{
    int lis1=1;
    int lis2=1;
    int m1=0;
    int m2=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]<=arr[i])
        {
            lis1++;
        }
        else
        {
            lis1=1;
            m1=max(m1,lis1);
        }
    }
    m1=max(m1,lis1);
    for(int i=1;i<m;i++)
    {
        if(arr2[i-1]<=arr2[i])
        {
            lis2++;
        }
        else
        {
            lis2=1;
            m2=max(m2,lis2);
        }
    }
     m2=max(m2,lis2);
    cout<<m1+m2<<"\n";
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
        int m;
        cin>>m;
        int arr[n];
        int arr2[m];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>arr2[i];
        }
        solve(arr,arr2,n,m);
    }
}