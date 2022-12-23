#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<char>> arr,int n,int m,int r,int c)
{
    bool b=false;
    if(arr[r-1][c-1]=='B')
    {
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        if(arr[r-1][i]=='B')
        {
            b=true;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][c-1]=='B')
        {
            b=true;
        }
    }
    if(b)
    {
        return 1;
    }
    return 2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int m;
        int r;
        int c;
        cin>>n>>m>>r>>c;
        vector<vector<char>> arr(n,vector<char>(m));
        int w=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='W')
                {
                    w++;
                }
            }
        }
        if(w==n*m)
        {
            cout<<"-1"<<'\n';
            continue;
        }
        cout<<solve(arr,n,m,r,c)<<"\n";
    }
}