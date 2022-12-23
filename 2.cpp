#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int solution(vector<int> &A, vector<int> &B, int n)
{
    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        p.first = A[i];
        p.second = i;
        c.push_back(p);
    }
    sort(c.begin(), c.end());
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (c[i].first != ans)
        {
            return ans;
        }
        if (B[c[i].second] != c[i].first)
        {
            return ans;
        }
        ans++;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout<<solution(a,b,n)<<"\n";
}