#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

typedef vector<ll> vi;

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
bool compare(pair<int,int> &p1,pair<int,int> &p2)
{
    if(p1.first==p2.first)
    {
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}
void solve()
{
    int n;
    cin>>n;
    vi a(n,0);
    vi b(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    vi a1=a;
    vi b1=b;

    vector<pair<int,int>> v1;

    for(int i=0;i<n;i++)
    {
        v1.push_back({a[i],b[i]});
    }

    sort(a1.begin(),a1.end());
    sort(b1.begin(),b1.end());
    sort(v1.begin(),v1.end(),compare);

    vector<pair<int,int>> v2;

    for (int i = 0; i < n; i++)
    {
        v2.push_back({a1[i],b1[i]});
    }
    bool bo=true;
    for(int i=0;i<n;i++)
    {
        if((v1[i].first!=v2[i].first) || (v1[i].second!=v2[i].second))
        {
            bo=false;
            break;
        }
    }
    vector<pair<int,int>> res;
    if(bo)
    {
        if(!(is_sorted(a.begin(),a.end())))
        {
            for(int i=0;i<n;i++)
            {
                for(int j=i;j<n;j++)
                {
                    if(a[i]>a[j])
                    {
                        swap(a[i],a[j]);
                        swap(b[i],b[j]);
                        res.push_back({i+1,j+1});
                    }
                }
            }
        }
        if(!(is_sorted(b.begin(),b.end())))
        {
            for(int i=0;i<n;i++)
            {
                for(int j=i;j<n;j++)
                {
                    if(b[i]>b[j])
                    {
                        swap(a[i],a[j]);
                        swap(b[i],b[j]);
                        res.push_back({i+1,j+1});
                    }
                }
            }
        }
        cout<<res.size()<<"\n";
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i].first<<" "<<res[i].second<<"\n";
        }
    }
    else
    {
        cout<<"-1\n";
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
        solve();
    }
}