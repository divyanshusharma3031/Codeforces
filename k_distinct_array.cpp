#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(int n,int k)
{
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        arr[i]=i+1;
    }
    int cur=0;
    int x=(n*(n+1))/2-k;
    cout<<x<<"\n";
    for(int i=n-1;i>=1;i++)
    {
        if(x<=0)
        {
            break;
        }
        else if((x-i)>=0)
        {
            arr[cur]=1;
            x=x-i;
        }
        else
        {
            int extra=i-x;
            arr[cur+extra]=1;
            x=0;
        }
        cur++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
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
        int k;
        cin>>k;
        solve(n,k);
    }
}