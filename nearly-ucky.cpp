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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll c=0;
    while(n>0)
    {
        ll rem=n%10;
        if(rem==4 || rem==7)
        {
            c++;
        }
        n=n/10;
    }
    if(c==4 || c==7)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}