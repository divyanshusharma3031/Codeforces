#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> arr,vector<int> aux,int n)
{
    vector<int> x;
    int mx=-1;
    do
    {
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans+(aux[i]^arr[i]);
        }
        if(mx<ans)
        {
            x=aux;
            mx=ans;
        }
    } while (next_permutation(aux.begin(),aux.end()));
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<"\n"<<mx<<"\n";
    
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
        vector<int> arr(n,0);
        vector<int> aux(n,0);
        for(int i=0;i<n;i++)
        {
            arr[i]=i+1;
            aux[i]=i+1;
        }
        solve(arr,aux,n);
    }
}