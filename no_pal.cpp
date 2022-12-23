#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{
    string ans;
    int i=0;
    char c='a';
    char z='z';
    while(i<n)
    {
        ans+=c;
        if(c=='z')
        {
            c='a';
            i++;
            continue;
        }
        c++;
        i++;
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
        solve(n);
    }
}