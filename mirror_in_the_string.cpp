#include<bits/stdc++.h>
using namespace std;
void solve(string s,int n)
{
    int i=0;
    string str="";
    str+=s[0];
    if(s[0]==s[1])
    {
        cout<<str+str<<'\n';
        return;
    }
    while((i<n-1) && (s[i]>=s[i+1]))
    {
        str+=s[i+1];
        i++;
    }
    string str2="";
    i=str.length()-1;
    while(i>=0)
    {
        str2+=str[i];
        i--;
    }
    cout<<str+str2<<'\n';
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(s,n);
    }
}