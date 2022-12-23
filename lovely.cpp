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

void solve(vector<ll> arr,ll n)
{
    if(n==1)
    {
        if(arr[0]%2)
        {
            cout<<arr[0]<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
        return;
    }
    vector<ll> odd;
    vector<ll> even;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]%2)
        {
            odd.push_back(arr[i]);
        }
        else
        {
            even.push_back(arr[i]);
        }
    }
    if(even.size()==n)
    {
        cout<<"-1\n";
        return;
    }
    if(((odd.size()==n) && (odd.size() %2)) || odd.size()==1)
    {
        cout<<"-1\n";
        return;
    }
    if((odd.size()%2)==0)
    {
        for(int i=0;i<even.size();i++)
        {
            cout<<even[i]<<" ";
        }
        for(int i=0;i<odd.size();i++)
        {
            cout<<odd[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    else
    {
        cout<<odd[0]<<" ";
        for(int i=0;i<even.size();i++)
        {
            cout<<even[i]<<" ";
        }
        for(int i=1;i<odd.size();i++)
        {
            cout<<odd[i]<<" ";
        }
        // cout<<odd[odd.size()-1]<<"\n";
        cout<<"\n";
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
        vector<ll> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
    }
}
