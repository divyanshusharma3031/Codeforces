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

void solve(ll n,ll m,ll a,ll b)
{
    ll mn=INT_MAX;
    for(int i=0;i<=n;i++)
    {
        if((n-m*i)<0)
        {
            mn=min(mn,b*i);
            break;
        }
        mn=min(mn,b*i+a*(n-m*i));
    }
    cout<<mn<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll m;
    ll n;
    ll a;
    ll b;
    cin>>n>>m>>a>>b;
    solve(n,m,a,b);
}
