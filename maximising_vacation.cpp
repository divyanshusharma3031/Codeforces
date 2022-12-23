#include<bits/stdc++.h>
using namespace std;
void solve(string s,int n,int x)
{
    vector<int> l(n,0);
    vector<int> r(n,0);
    int c=0;
    l[0]=0;
    if(s[0]=='0')
    {
        c++;
    }
    for(int i=1;i<n;i++)
    {
        l[i]=c;
        if(s[i]=='0')
        {
            c++;
        }
        else
        {
            c=0;
        }
    }
    r[n-1]=0;
    c=0;
    if(s[n-1]=='0')
    {
        c++;
    }
    for(int i=n-2;i>=0;i--)
    {
        r[i]=c;
        if(s[i]=='0')
        {
            c++;
        }
        else
        {
            c=0;
        }
    }
    int ans=0;
    int idx=-1;
    int mx=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            if((l[i]+r[i]+1)>=mx)
            {
                mx=max(mx,l[i]+r[i]+1);
                idx=i;
            }
        }
    }
    c=0;
    ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0' || idx==i)
        {
            c++;
            if(c>=x)
            {
                ans++;
                c=0;
            }
        }
        else
        {
            c=0;
        }
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
        cin>>n;
        int x;
        cin>>x;
        string s;
        cin>>s;
        solve(s,n,x);
    }
}