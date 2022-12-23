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
    ll q;
    cin>>q;
    vi arr(n,0);
    ll s=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    sort(arr.begin(),arr.end());
    vi suf(n,0);
    suf[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suf[i]=suf[i+1]+arr[i];
    }
    while(q--)
    {
        ll x;
        ll y;
        cin>>x;
        cin>>y;
        if(x==y)
        {
            cout<<suf[n-x]<<"\n";
            continue;
        }
        ll sum=suf[n-x];
        ll neg=suf[n-x+y];
        cout<<sum-neg<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while (t--)
    {
        solve();
    }
}