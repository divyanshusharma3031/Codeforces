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

void solve(ll x,ll y)
{
    if(x==0 && y==0)
    {
        cout<<"0\n";
        return;
    }
    float d=sqrt(pow(x*1.0,2)+pow(y*1.0,2));
    if(d==int(d))
    {
        cout<<"1\n";
    }
    else
    {
        cout<<"2\n";
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
        ll x;
        cin>>x;
        ll y;
        cin>>y;
        solve(x,y);
    }
}
