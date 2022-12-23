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
        cin >> m;
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++)
        {
            int c1;
            int c2;
            cin >> c1;
            cin >> c2;
            v.push_back({c1, c2});
        }
        sort(v.begin(),v.end(),compare);
        int i=0;
        int s=0;
        while(i<)
    }
}
