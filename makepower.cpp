#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n)
{
    int su=0;
    for(int i=0;i<n;i++)
    {
        su+=arr[i];
    }
    float f=log2(su);
    if(f==int(f))
    {
        cout<<"0"<<"\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=log2(arr[i]);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> v;
}
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
    }
}