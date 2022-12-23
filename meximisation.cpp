#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n)
{
    sort(arr,arr+n);
    vector<int> ans;
    vector<int> aux;
    for(int i=0;i<n;)
    {
        ans.push_back(arr[i]);
        int j=i+1;
        while(j<n && arr[i]==arr[j])
        {
            aux.push_back(arr[j]);
            j++;
        }
        i=j;
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    for(int i=0;i<aux.size();i++)
    {
        cout<<aux[i]<<" ";
    }
    cout<<'\n';
    return ;
}
int main()
{
    int t;
    cin>>t;
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
    return 0;
}