#include<bits/stdc++.h>
using namespace std;
bool palindrome(string s)
{
    int n=s.length();
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(string s,int n,int k)
{
    int i=0;
    while(i<n-1 && s[i]==s[i+1])
    {
        i++;
    }
    if(i==n-1)
    {
        cout<<"1"<<"\n";
        return;
    }
    if(k==0)
    {
        cout<<"1\n";
        return;
    }
    if(palindrome(s))
    {
        cout<<"1\n";
        return;
    }
    cout<<"2\n";
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