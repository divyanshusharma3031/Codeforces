#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> arr,int n)
{
    vector<int> ans;
    ans.push_back(arr[0][2]);
    int l=arr[0][0];
    int u=arr[0][1];
    int m=arr[0][2];
    int p=1;
    while(p<n && u==arr[p][1])
    {
        m=min(arr[p][2],m);
        ans.push_back(m);
        p++;
    }
    for(int i=p;i<n;i++)
    {
        if(u==arr[i][1] && l==arr[i][0])
        {
            ans.push_back(min(m,arr[i][2]));
            m=min(m,arr[i][2]);
            continue;
        }
        if(l>arr[i][0])
        {
            if((arr[i][1]-arr[i][0])>(u-l))
            {
                ans.push_back(arr[i][2]);
            }
            else if((arr[i][1]-arr[i][0])==(u-l))
            {
                ans.push_back(arr[i][2]);
            }
            else
            {
                ans.push_back(ans[i-1]+arr[i][2]);
            }
            l=arr[i][0];
            m=arr[i][2];
            continue;
        }
        if(u<=arr[i][1])
        {
           if((arr[i][1]-l)>(arr[i][1]-arr[i][0]))
           {
               ans.push_back(arr[i][2]+m);
           }
           else if((arr[i][1]-l)==(arr[i][1]-arr[i][0]))
           {
               ans.push_back(min(m+arr[i][2],arr[i][2]));
               m=min(m+arr[i][2],arr[i][2]);
           }
           else if((arr[i][1]-l)<(arr[i][1]-arr[i][0]))
           {
               ans.push_back(arr[i][2]);
               l=arr[i][0];
           }
           u=arr[i][1];
        }
        else
        {
            ans.push_back(arr[i-1][2]);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"\n";
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
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
        {
            int l;
            int r;
            int c;
            cin>>l;
            cin>>r;
            cin>>c;
            arr.push_back({l,r,c});
        }
        solve(arr,n);
    }
}