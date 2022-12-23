#include<bits/stdc++.h>
using namespace std;
void solve(string n)
{
    vector<int> arr;
    int ans=0;
    int i=0;
    while(i<n.length())
    {
        arr.push_back(n[i]-48);
        i++;
    }
    if(arr.size()==1)
    {
        cout<<n<<"\n";
    }
    int i1=-1;
    int i2=-1;
    int mx=0; 
    reverse(arr.begin(),arr.end());
    for(int i=0; i<arr.size()-1;i++ )
    {
        if((arr[i]+arr[i+1])>=10)
        {
            i1=i;
            i2=i+1;
            int s=arr[i]+arr[i+1];
            arr[i]=s%10;
            arr[i+1]=s/10;
            break;
        }
    }
    reverse(arr.begin(),arr.end());
    if(i1==i2)
    {
        ans+=arr[0]+arr[1];
        arr[0]=ans/10;
        arr[1]=ans%10;
    }
    i=0;
    while(i<arr.size() && arr[i]==0)
    {
        i++;
    }
    while(i<arr.size())
    {
        cout<<arr[i];
        i++;
    }
    cout<<'\n';
    return;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string n;cin>>n;
        solve(n);   
    }
}