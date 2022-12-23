#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void reverse(int lo,int hi,vector<int> &arr)
{
    while(lo<=hi)
    {
        swap(arr[lo],arr[hi]);
        lo++;
        hi--;
    }
}

int sellingproducts(int arr[],int n,int m)
{
    map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }
    int x=mpp.size();
    for(auto i:mpp)
    {
        if(i.second<=m)
        {
            m-=i.second;
            x--;
        }
        else
        {
            break;
        }
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int m;
        cin>>m;
        cout<<sellingproducts(arr,n,m)<<"\n";
    }
}
