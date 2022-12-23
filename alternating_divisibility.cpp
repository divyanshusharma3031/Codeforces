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
void solve(int n)
{
    vector<ll> arr(n+1);
    int s=1;
    arr[1]=s;
    int i=3;
    while(i<=n)
    {
        s+=2;
        arr[i]=s;
        i+=2;
    }
    i=2;
    while(i<=n)
    {
        arr[i]=arr[i-1]*2;
        i+=2;
    }
    for(int i=1;i<=n;i++)
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
       ll n;
       cin>>n;
       solve(n);
    }
}
