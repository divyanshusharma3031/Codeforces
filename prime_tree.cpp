#include<bits/stdc++.h>
using namespace std;
void Sort(vector<pair<int, int> > &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i].first > v[i].second)
        {
            swap(v[i].first, v[i].second);
        }
    }
}
void solve(vector<pair<int,int> > v)
{
    Sort(v);
    unordered_map<int,vector<int>> mpp;
    for (int i = 0; i < v.size(); i++)
    {
        
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        for(int i=0; i<n-1; i++)
        {
            pair<int,int> p;
            cin>>p.first;
            cin>>p.second;
            v.push_back(p);
        }
        solve(v);
    }
}