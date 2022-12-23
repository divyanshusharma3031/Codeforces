#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(string s,int n,int k)
{
    int arr[26]={0};
    for(int i=0;i<n;i++)
    {
        arr[s[i]-'a']++;
    }
    int p=0;
    int odd=0;
    for(int i=0;i<26;i++)
    {
        p+=(arr[i]/2);
        odd+=(arr[i]%2);
    }
    // cout<<p<<"\n";
    // cout<<odd<<"\n";
    ll ans=2*(p/k);
    odd+=2*(p%k);
    if(odd>=k)
    {
        ans++;
    }
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
        int n;
        int k;
        cin>>n;
        cin>>k;
        string s;
        cin>>s;
        solve(s,n,k);
    }
}