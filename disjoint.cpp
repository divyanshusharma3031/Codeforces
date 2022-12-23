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
void solve(int n,vector<int> &arr)
{
    int z=0;
    int o=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            o++;
        }
        else
        {
            z++;
        }
    }
    cout<<max(o,z)<<"\n";
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
       vector<int> arr(n);
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       solve(n,arr);
    }
}
