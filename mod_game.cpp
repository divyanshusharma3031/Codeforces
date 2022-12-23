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
void solve(int l,int r,int a)
{
    int i=r;
    int ans=-1;
    int w=r/a;
    int ab=w*a-1;
    if(ab<l)
    {
        ab=l;
    }
    ans=r/a+r%a;
    ans=max(ans,ab/a+ab%a);
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        int l;
        cin>>l;
        int r;
        cin>>r;
        int a;
        cin>>a;
        solve(l,r,a);
    }
}
