#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool issafe(vector<vector<int>> &arr,int x,int y,int n)
{
    for(int i=0;i<x;i++)
    {
        if(arr[i][y]==1)
        {
            return false;
        }
    }

    while(x>=0 && y>=0)
    {
        if(arr[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    return true;
}

bool nqueen(vector<vector<int>> &arr,int x,int n)
{
    if(x>=n)
    {
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(issafe(arr,x,i,n))
        {
            arr[x][i]=1;
            if(nqueen(arr,x+1,n))
            {
                return true;
            }
            arr[x][i]=0;
        }
    }
    return false;
}

int main()
{
    int n=4;
    vector<vector<int>> arr(n,vector<int>(n,0));
    nqueen(arr,0,4);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}