#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define int long long

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
void solve()
{
    ll n;
    
    cin >> n;
    
    vector<int> arr(n+1,0);

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    if(arr[1]%2==0)
    {
        cout<<"NO\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(arr[i]%2)
        {

        }
        else if((arr[i]%(i+1))!=0)
        {
            //
        }
        else
        {
            int j=i;
            while(j>1 && (arr[i]%j==0))
            {
                j--;
            }
            if(j==1)
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";

}
int32_t main()
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