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

void solve(vector<pair<int, int>> v, int n, string s)
{
    map<int, vector<pair<char,int>>> mpp;
    // cout<<n;
    for (int i = 0; i < n; i++)
    {
            
        if (mpp[v[i].second].size() < 2)
        {
            if ((mpp[v[i].second].size() != 0) && mpp[v[i].second][0].first != s[i])
            {
                if(mpp[v[i].second][0].second<v[i].first)
                    mpp[v[i].second].push_back({s[i],v[i].first});
            }
            else if ((mpp[v[i].second]).size() == 0)
            {
                mpp[v[i].second].push_back({s[i],v[i].first});
            }
        }
    }
    for (auto it : mpp)
    {
        // cout<<it.first<<" ";
        if (it.second.size() > 1)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    while (n--)
    {
        ll x;
        ll y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    string s;
    cin >> s;
    solve(v, s.length(), s);
}
