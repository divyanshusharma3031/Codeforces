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
void solve(string s,char c)
{
    int n=s.length();
    if(s.length()==1 && s[0]==c)
    {
        cout<<"YES\n";
        return;
    }
    if(s.length()==1)
    {
        cout<<"NO\n";
        return;
    }
    if(s.length()%2==0)
    {
        cout<<"NO\n";
        return;
    }
    vector<int> idx;
    for(int i=0;i<n;i++)
    {
        if(s[i]==c)
        {
            idx.push_back(i);
        }
    }

    for(int i=0;i<idx.size();i++)
    {
        if(idx[i]%2==0 && (n-idx[i]-1)%2==0)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin>>s;
        char c;
        cin>>c;
        solve(s,c);
    }
}
