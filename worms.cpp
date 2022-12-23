#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <deque>
using namespace std;

#define endl "\n"

typedef long long ll;

typedef vector<ll> vi;

void reverse(ll lo, ll hi, vector<ll> &arr)
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
    ll i = 0;
    ll n = s.length() - 1;
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
// ll findSubstring(string s)
// {
//     vector<ll> map(128, 0);
//     ll counter;            // check whether the substring is valid
//     ll begin = 0, end = 0; // two pollers, one poll to tail and one  head
//     ll d;                  // the length of substring

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
    auto sgn = [&](ll x)
    {
        if (x > 0)
            return 1;
        else
            return -1;
    };
    ll n;
    cin >> n;

    vi a(n, 0);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long sum = 0;
    for (ll i = 0; i < n; ++i)
    {
        ll cur = a[i];
        ll j = i;
        while (j < n && sgn(a[i]) == sgn(a[j]))
        {
            cur = max(cur, a[j]);
            ++j;
        }
        sum += cur;
        i = j - 1;
    }
    cout << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}