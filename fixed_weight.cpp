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
void solve(ll n,ll x)
{
    vector<ll> arr(n,0);
    if((2*n)>=x && ((x%2)==0))
    {
        cout<<"YES\n";
        return;
    }
    if(x==1)
    {
        cout<<"YES\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        double d=(double(x))/i;
        if(d==int(d))
        {
            int w=d;
            int sz=n-i+1;
            if(w<=sz)
            {
                cout<<"YES"<<"\n";
                return;
            }
        }
    }
    cout<<"NO\n";
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
        ll x;
        cin>>n>>x;
        solve(n,x);
    }
}



