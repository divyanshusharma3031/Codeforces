#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void reverse(int lo, int hi, vector<ll> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}

bool palindrome(string s)
{
    int i = 0;
    int n = s.length() - 1;
    if (n == 0)
    {
        return false;
    }
    while (i <= n)
    {
        if (s[i] != s[n])
        {
            return false;
        }

        i++;
        n--;
    }
    return true;
}

void solve(vector<ll> &arr,ll n)
{
    vector<ll> aux=arr;
    sort(aux.begin(),aux.end());
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        if(aux[i]!=arr[i])
        {
            v.push_back(i);
        }
    }
    if((v.size())==0)
    {
        cout<<"yes\n";
        cout<<"1 1\n";
        return;
    }
    reverse(v[0],v[v.size()-1],arr);
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            cout<<"no\n";
            return;
        }
    }
    cout<<"yes\n";
    cout<<v[0]+1<<" "<<v[v.size()-1]+1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> arr(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    solve(arr,n);
}