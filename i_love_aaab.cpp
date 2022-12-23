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

void solve(string s)
{
    if(s[s.length()-1]!='B')
    {
        cout<<"NO\n";
        return;
    }
    int n=s.length();
    int l1=0;
    int l2=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')
        {
            l1++;
        }
        else
        {
            while(i<n && s[i]=='B')
            {
                l2++;
                i++;
            }
            if(!(l2==1 || l1>=l2))
            {
                cout<<"NO\n";
                return;
            }
            i--;
            l2=0;
            l1=0;
        }
    }
    cout<<"YES\n";
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