#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{
    if(n==1)
    {
        cout<<"0"<<"\n";
        return;
    }
    if(n==2)
    {
        cout<<"0 1\n";
        return;
    }
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    vector<int> ans(n);
    
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
        solve(n);
    }
}