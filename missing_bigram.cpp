#include<bits/stdc++.h>
using namespace std;
void bigram(vector<string> v)
{
    string ans="";
    vector<string> poss; 
    ans=ans+v[0][0];
    ans+=v[0][1];
    poss.push_back(v[0]);
    bool t=false;
    for(int i=1;i<v.size();i++)
    {
        if(v[i-1][1]==v[i][0])
        {
            poss.push_back(v[i]);
            // ans+=v[i][1];
        }
        else
        {
            // ans+=v[i][0];
            string str="";
            str+=v[i-1][1];
            str+=v[i][0];
            poss.push_back(str);
            poss.push_back(v[i]);
            t=true;
        }
    }
    if(t)
    {
        for(int i=1;i<poss.size();i++)
        {
            ans+=poss[i][1];
        }
    }
    else
    {
        for(int i=1;i<poss.size();i++)
        {
            ans+=poss[i][1];
        }
        ans+="a";
    }
    cout<<ans<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> v;
        for(int i=0;i<n-2;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        bigram(v);
    }
    return 0;
}