#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(vector<int> arr,int n)
{
    sort(arr.begin(),arr.end());
    ll odd=0;
    ll even=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    if((odd%2==0) && (even%2==0))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
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
        int n;
        cin>>n;
        vector<int> arr(2*n,0);
        for(int i=0;i<2*n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,2*n);
    }
}