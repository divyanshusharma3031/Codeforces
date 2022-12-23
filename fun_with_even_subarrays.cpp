#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n)
{
    int i=0;
    int ele=arr[0];
    while(i<n)
    {
        if(ele!=arr[i])
        {
            break;
        }
        i++;
    }
    if(i==n)
    {
        cout<<"0"<<"\n";
        return;
    }
    if(n==2)
    {
        cout<<"1\n";
        return;
    }
    i=0;
    int mx=0;
    int j=n-1;
    ele=arr[j];
    while(ele==arr[j])
    {
        j--;
        mx++;
    }
    int x=n-mx;
    int ans=0;
    i=j;
    while(i>=0)
    {
        int w=i;
        int y=0;
        int s=mx;
        bool b=false;
        while(y<mx && w>=0)
        {
            if(arr[w]!=ele)
            {
                b=true;
            }
            y++;
            w--;
        }
        if(b)
        {
            ans++;
        }
        i=w;
        
        mx=mx*2;
        while(arr[i]==ele)
        {
            i--;
            mx++;
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
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
    }
}