#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int n)
{
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        s.insert(i);
    }
    vector<int> aux;
    int op=0;
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i])!=s.end())
        {
            s.erase(arr[i]);
        }
        else
        {
            aux.push_back(arr[i]);
        }
    }
    sort(aux.begin(),aux.end());
    for(int i=0;i<aux.size();i++)
    {
        int x=*(s.begin());
        float w=float(aux[i])/2;
        if((w >x))
        {
            op++;
            s.erase(x);
        }
        else
        {
            cout<<"-1\n";
            return;
        }
    }
    cout<<op<<"\n";
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}