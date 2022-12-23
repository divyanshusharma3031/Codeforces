#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n)
{
    vector<int> ans;
    set<int> s;
    vector<int> fre(n+1,0);
    int mex=n+1;
    for(int i=0;i<n;i++)
    {
        fre[arr[i]]++;
    }
    for(int i=0;i<=n;i++)
    {
        if(fre[i]==0)
        {
            mex=i;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
        {
            ans.push_back(mex);
            for(int i=0;i<mex;i++)
            {
                s.insert(i);
            }
        }
        fre[arr[i]]--;
        if(s.find(arr[i])!=s.end())
        {
            s.erase(arr[i]);
        }
        if(fre[arr[i]]==0)
        {
            mex=min(mex,arr[i]);
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return;
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