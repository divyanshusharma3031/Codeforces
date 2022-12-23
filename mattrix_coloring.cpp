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
        ll m;
        cin>>m;
        ll x1;
        ll y1;
        ll x2;
        ll y2;
        cin>>x1>>y1;
        cin>>x2>>y2;
        int matrix[n+1][m+1];
        matrix[x1][y1]=1;
        matrix[x2][y2]=2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(matrix[i][j]==1 || matrix[i][j]==2)
                {
                    //pass
                }
                else
                {
                    if(matrix[i][j-1]==1)
                    {
                        if(matrix[i][j+1]==2 || matrix[i+1][j]==2 || matrix[i-1][j]==2)
                        {
                            matrix[i][j]=3;
                        }
                        else
                        {
                            matrix[i][j]=2;
                        }
                    }
                    else if(matrix[i][j+1]==1)
                    {
                        if(matrix[i][j-1]==2 || matrix[i+1][j]==2 || matrix[i-1][j]==2)
                        {
                            matrix[i][j]=3;
                        }
                        else
                        {
                            matrix[i][j]=2;
                        }
                    }
                    else if(matrix[i][j-1]==2)
                    {
                        if(matrix[i][j+1]==1 || matrix[i+1][j]==1 || matrix[i-1][j]==1)
                        {
                            matrix[i][j]=3;
                        }
                        else
                        {
                            matrix[i][j]=1;
                        }
                    }
                    else if(matrix[i][j+1]==2)
                    {
                        if(matrix[i][j-1]==1 || matrix[i+1][j]==1 || matrix[i-1][j]==2)
                        {
                            matrix[i][j]=3;
                        }
                        else
                        {
                            matrix[i][j]=1;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
