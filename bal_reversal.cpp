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

void solve(vector<ll> &arr,ll n,ll x)
{
    sort(arr.begin(),arr.end());
    int c=0;
    int aux=x;
    for(int i=0;i<n;i++)
    {
        if(aux>=arr[i])
        {
            c++;
            aux-=arr[i];
        }
        else
        {
            aux=aux-ceil(arr[i]/2.0);
            if(aux>=0)
            {
                c++;
                break;
            }
        }
    }
    cout<<c<<"\n";
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
        ll x;
        cin>>x;
        vector<ll> v;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        solve(v,n,x);
    }
}
