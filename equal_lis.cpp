#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{
    bool b=false;
    int w=n;
    if(n==2)
    {
        cout<<"NO"<<"\n";
        return;
    }
    if(n%2==0)
    {
        cout<<"YES"<<"\n";
        cout<<n/2<<" ";
        for(int i=1;i<n/2;i++)
        {
            cout<<i<<" ";
        }
        for(int i=n;i>n/2;i--)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    vector<int> arr(n/2+1);
    vector<int> arr2(n/2);
    int c=1;
    int i=0;
    while(c<=n)
    {
        arr[i]=c;
        c+=2;
        i++;
    }
    int x=n-1;
    i=0;
    while(x>=2)
    {
        arr2[i]=x;
        x=x-2;
        i++;
    }
    cout<<"YES"<<"\n";
    for(int j=0; j<arr.size(); j++)
    {
        cout<<arr[j]<<" ";
    }
    for(int j=0; j<arr2.size(); j++)
    {
        cout<<arr2[j]<<" ";
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