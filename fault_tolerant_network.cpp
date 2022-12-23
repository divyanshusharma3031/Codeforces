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

void solve(vector<int> &a,vector<int> & b,int n)
{
    int mn=abs(a[0]-b[0])+abs(a[n-1]+b[n-1]);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++)
    {
        
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
        vector<int> a(n,0);
        vector<int> b(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        solve(a,b,n);
    }
}
