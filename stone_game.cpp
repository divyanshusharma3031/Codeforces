#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(int n,string a,string b)
{
    vector<char> ans(2*n);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    int startA=0;
    int endA=n-1;
    int startB=0;
    int endB=n-1;
    int front=0;
    int back=2*n-1;
    for(int i=0;i<2*n;i++)
    {
        if((i%2)==0)
        {
            if(startB<=endB && a[startA]>=b[startB])
            {
                ans[back--]=a[endA--];
            }
            else
            {
                ans[front++]=a[startA++];
            }
        }
        else
        {
            if(startA<=endA && a[startA]<b[startB])
            {
                ans[front++]=b[startB++];
            }
            else
            {
                ans[back--]=b[endB--];
            }
        }
    }
    for(auto it:ans)
    {
        cout<<it;
    }
    cout<<"\n";
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
        string a;
        string b;
        cin>>a>>b;
        solve(n,a,b);
    }
}