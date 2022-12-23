#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void reverse(int lo, int hi, vector<int> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}

bool palindrome(string s)
{
    int i = 0;
    int n = s.length() - 1;
    if (n == 0)
    {
        return false;
    }
    while (i <= n)
    {
        if (s[i] != s[n])
        {
            return false;
        }

        i++;
        n--;
    }
    return true;
}
bool compare(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2)
{
    return p1.second<p2.second;
}
void solve(vector<pair<pair<int,int>,int>> &v,int n)
{
    int m=v.size();
    sort(v.begin(),v.end(),compare);//sort by weight;
    vector<pair<int,int>> ans;
    int x=0;
    for(int i=0;i<m;)
    {
        x+=v[i].second+v[i+1].second;
        ans.push_back({v[i].first.second,v[i].first.first});
        ans.push_back({v[i+1].first.second,v[i+1].first.first});
        if(ans.size()==2*n)
        {
            break;
        }
        i+=2;
    }
    cout<<x<<"\n";
    sort(ans.begin(),ans.end());
    for(int i=0;i<n;i++)
    {
        cout<<ans[i].second<<" "<<ans[2*n-1-i].second<<"\n";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll m;
        cin>>m;
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<m;i++)
        {
            int x;
            int w;
            cin>>x>>w;
            v.push_back({{i+1,x},w});
        }
        solve(v,n);
    }
}