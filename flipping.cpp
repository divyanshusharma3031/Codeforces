#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
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
// int findSubstring(string s)
// {
//     vector<int> map(128, 0);
//     int counter;            // check whether the substring is valid
//     int begin = 0, end = 0; // two pointers, one point to tail and one  head
//     int d;                  // the length of substring

//     // for ()
//     // { /* initialize the hash map here */
//     // }

//     while (end < s.size())
//     {

//             if(map[s[end++]]-- )
//             { /* modify counter here */
//             }

//             while (/* counter condition */)
//             {

//                 /* update d here if finding minimum*/

//                 // increase begin to make it invalid/valid again

//                 if(map[s[begin++]]++ )
//                 { /*modify counter here*/
//                 }
//             }

//             /* update d here if finding maximum*/
//     }
//     return d;
// }
void solve()
{
    ll n;

    cin >> n;

    vi arr(n, 0);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll pref=0;
    ll ans=0;
    vector<int> suff(n,0);
    if(arr[n-1]==1)
    {
        suff[n-1]=1;
    }
    for(ll i=n-2;i>=0;i--)
    {
        if(arr[i]==1)
        {
            suff[i]=suff[i+1]+1;
        }
        else
        {
            suff[i]=suff[i+1];
        }
    }
    for(ll i=0;i<n;i++)
    {
        ll c=0;
        for(ll j=i;j<n;j++)
        {
            if(arr[j]==0)
            {
                c++;
            }
            if((j+1)<n)
            {
                ans=max(ans,pref+c+suff[j+1]);
                
            }
            else
            {
                ans=max(ans,pref+c);
            }
        }
        if(arr[i]==1)
        {
            pref++;
        }
    }
    // 8
    // 1 0 0 0 1 0 0 0
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--)
    {
        solve();
    }
}