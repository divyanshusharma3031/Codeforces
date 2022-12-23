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

const int m=2*(1e5);
vector<int> dp(m,-1);

ll sol(string &s,ll i)
{
    if(i>=s.length())
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    if(i==(s.length()-1))
    {
        return 1;
    }
    if((i<s.length()-1) && s[i]==s[i+1])
    {
        return sol(s,i+2);
    }
    else
    {
        int j;
        for(j=i+1;j<s.length();j++)
        {
            if(s[i]==s[j])
            {
                break;
            }
        }
        if(j==s.length())
        {
            return dp[i]=1+sol(s,i+1);
        }
        return dp[i]=min(j-i-1+sol(s,j+1),1+sol(s,i+1));
    }
}

void solve(string s)
{
    for(int i=0;i<=s.length();i++)
    {
        dp[i]=-1;
    }
    cout<<sol(s,0)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        solve(s);
    }
}
