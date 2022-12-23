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
void solve(vector<string> &arr, ll n)
{
    map<char, map<int,long long>> mpp1;
    map<char, map<int,long long>> mpp2;
    for(int i=0;i<n;i++)
    {
        mpp1[arr[i][0]][arr[i][1]-'a']++;
        mpp2[arr[i][1]][arr[i][0]-'a']++;
    }
    ll ans=0;
    for(auto it:mpp1)
    {
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                ans+=it.second[i]*it.second[j];
            }
        }
    }
    for(auto it:mpp2)
    {
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                ans+=it.second[i]*it.second[j];
            }
        }
    }
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
        ll n;
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        solve(v, n);
    }
}