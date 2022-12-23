#include <bits/stdc++.h>
using namespace std;
bool compare(pair<char, int> p1, pair<char, int> p2)
{
    return p1.second < p2.second;
}
void solve(string s, int n)
{
    if (n % 2)
    {
        cout << "NO"
             << "\n";
        return;
    }
    map<char, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[s[i]]++;
        if (mpp[s[i]] > (n / 2))
        {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    map<int, int> vis;
    vector<pair<char, int>> v;
    for (auto i = mpp.begin(); i != mpp.end(); i++)
    {
        v.push_back({i->first, i->second});
        vis[i->second]++;
    }
    cout << "YES"
         << "\n";
    string str;
    int i = 0;
    sort(v.begin(), v.end(), compare);
    while (i < v.size())
    {
        int z = v[i].second;
        while (z--)
        {
            str += v[i].first;
        }
        i++;
    }
    int w = n / 2-1;
    i=0;
    while (i <=w)
    {
        swap(str[i],str[w]);
        i++;
        w--;
    }
    cout<<str<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s, n);
    }
}