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

void solve(string s,int n)
{
    int c=0;
    for(int i=0;i<n-2;i++)
    {
        string str=char(s[i])+char(s[i+1])+char(s[i+2]);
        if(str=="010")
        {
            c+=1;
        }
        else if(str=="001")
        {
            c+=2;
        }
        else if(str=="000")
        {
            c+=6;
        }
    }
    cout<<c<<"\n";
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
        solve(s, n);
    }
}
