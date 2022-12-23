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

int dpapproach(int curr,int h,int a,vector<vector<int>> &dp)
{
    if(h<=0 || a<=0)
    {
        return 0;
    }

    if(dp[a][h]!=-1)
    {
        return dp[a][h];
    }

    if(curr!=1)
    {
        return dp[a][h]=1+dpapproach(1,h+3,a+2,dp);
    }
    return dp[a][h]=max(1+dpapproach(2,h-5,a-10,dp),1+dpapproach(3,h-20,a+5,dp));
}

void solve()
{
    int h;
    int a;
    cin>>h>>a;
    vector<vector<int>> dp(2000,vector<int>(2000,-1));
    cout<<dpapproach(1,h+3,a+2,dp)<<"\n";
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