#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    set<int> s;
    set<int> s2;
    vector<int> aux1;
    vector<int> aux2;
    int i=0;
    bool b=true;
    while(i<2*n)
    {
        if(b)
        {
            aux1.push_back(arr[i]);
            b=false;
        }
        else
        {
            aux2.push_back(arr[i]);
            b=true;
        }
        i++;
    }
    for(int i=0;i<=n;i++)
    {
        s.insert(i);
    }
    for(int i=0;i<aux1.size();i++)
    {
        s.erase(aux1[i]);
    }
    int x=*s.begin();
    for(int i=0;i<=n;i++)
    {
        s2.insert(i);
    }
    for(int i=0;i<aux2.size();i++)
    {
        s2.erase(aux2[i]);
    }
    int y=*s2.begin();
    if(x==y)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
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
        int n;
        cin >> n;
        vector<int> arr(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}