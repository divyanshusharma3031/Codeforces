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

void solve(vector<pair<int,pair<int,int>>> v,int n)
{
    int preva=-1;
    int prevb=-1;
    for(int i=0;i<n;i++)
    {
        if(v[i].first==1)
        {
            cout<<"YES"<<"\n";
            preva=v[i].second.first;
            prevb=v[i].second.second;
        }
        else
        {
            if(v[i].second.first==v[i].second.second)
            {
                preva=prevb=v[i].second.first;
                cout<<"YES\n";
            }
            else if(preva!=-1 && prevb!=-1)
            {
                if(min(preva,prevb)<=min(v[i].second.first,v[i].second.second))
                {
                    if(preva > min(v[i].second.first,v[i].second.second))
                    {
                        preva=min(v[i].second.first,v[i].second.second);
                    }
                    cout<<"YES\n";
                }
                else
                {
                    cout<<"NO\n";
                }
            }
            else
            {
                cout<<"NO\n";
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<pair<int,pair<int,int>>> v;
        while(n--)
        {
            int r;
            cin>>r;
            int a;
            int b;
            cin>>a>>b;
            v.push_back({r,{a,b}});
        }
        solve(v,v.size());
    }
}
