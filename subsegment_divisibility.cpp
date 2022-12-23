#include<bits/stdc++.h>
using namespace std;
vector<int> ans(500,0);
void solve(int n)
{
    int j=2;
    for(int i=0;i<n;i++)
    {
        cout<<j<<" ";
        if(i%2)
        {
            j+=3;
        }
        else
        {
            j++;
        }
    }
    cout<<"\n";
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
        solve(n);   
    }
}