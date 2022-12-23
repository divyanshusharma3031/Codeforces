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

void solve(vector<int> &a,vector<int> &b,int n,int d)
{
    ll mx=INT_MIN;
    ll i=1;
    while(i<=n)
    {
        int j=a[i];
        while(j<=n)
        {
            if((i*j)<mx)
            {
                break;  
            }
            mx=max(mx,i*j-d*(b[i]^b[j]));
            j++;
        }
        i++;
    }
    cout<<mx<<"\n";
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
        ll d;
        cin>>d;
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
        }
        solve(a,b,n,d);
    }
}
