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

void solve(ll n, string s)
{
    vector<pair<int,int>> v;
    int c=0;;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            c++;
            v.push_back({i+1,n-i});
            for(int j=i;j<n;j++)
            {
                if(s[j]=='0')
                {
                    s[j]='1';
                }
                else
                {
                    s[j]='0';
                }
            }
        }
    }    
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
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
        string s;
        cin >> s;
        solve(n, s);
    }
}
