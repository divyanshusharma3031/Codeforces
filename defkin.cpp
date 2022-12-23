#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

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

bool compare(pair<ll,ll> p1,pair<ll,ll> p2)
{
    return p1.second<p2.second;
}

void solve()
{
    int w;
    
    int h;
    
    int n;
    
    cin>>w>>h>>n;

    vector<ll> x;
    vector<ll> y;

    for(int i=0;i<n;i++)
    {
        int a;
        int b;
        cin>>a;
        cin>>b;
        x.push_back(a);
        y.push_back(b);
    }
    x.push_back(w+1);
    y.push_back(h+1);

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    long long X=x[0];
    long long Y=y[0];
    for(int i=1;i<x.size();i++)
    {
        X=max(X,x[i]-x[i-1]);
    }
   
    for(int i=1;i<y.size();i++)
    {
        Y=max(Y,y[i]-y[i-1]);
    }
    long long ans=(X-1)*(Y-1);
    cout<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}