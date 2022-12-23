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
void solve(int n,string s)
{
    if(s[n]=='0' || s[0]=='0' || s[1]=='0') 
    {
        cout<<"NO\n";
        return;
    }
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            reverse((i-1+n)%n,i,arr);
        }
    }
    cout<<"YES\n";
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
        string s;
        cin>>n;
        cin>>s;
        solve(n,s);
    }
}
