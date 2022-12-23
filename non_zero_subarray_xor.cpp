#include<bits/stdc++.h>
using namespace std;
int cal(int x,int y)
{
    int n=21;
    for(int i=0;i<n;i++)
    {
        if((y&(1<<i))>0)
        {
            x^=(1<<i);
        }   
    }
    return x;
}
void solve(int n)
{
    vector<int> ans;
    int x=0;
    int y=1;
    map<int,int> mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++)
    {
        int z=cal(x,y);
        while(mpp[cal(x,y)]==1)
        {
            z=cal(x,y);
            y++;
        }
        x=cal(x,y);
        mpp[z]=1;
        ans.push_back(y);
        y++;
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    //1000000
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        solve(n);
    }
}