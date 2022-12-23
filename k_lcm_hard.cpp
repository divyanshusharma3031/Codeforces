#include<bits/stdc++.h>
using namespace std;
void finding(int n,int k)
{
    vector<int> arr;
    while(k!=3)
    {
        arr.push_back(1);
        k--;
        n--;
    }
    vector<int> ans(3,0);
    if(n%2)
    {
        ans[0]=1;
        ans[1]=n/2;
        ans[2]=n/2;
    }
    else
    {
        int x=n/2;
        if(x%2)
        {
            ans[0]=2;
            x=n-2;
            x=x/2;
            ans[1]=x;
            ans[2]=x;
        }
        else
        {
            ans[0]=n/2;
            int x=n/2;
            ans[1]=x/2;
            ans[2]=x/2;
        }
    }
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    for(int i=0;i<k;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
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
        finding(n,k);
    }
}