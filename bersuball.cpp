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
    vi b(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll m;

    cin >> m;

    vi g(m, 0);

    map<int, int> mpp;

    for (ll i = 0; i < m; i++)
    {
        cin >> g[i];
    }

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        bool bo=false;
        for (ll j = 0; j < m; j++)
        {
            
            if (mpp[j] == 0)
            {
                // cout<<b[i]<<" "<<g[j]<<"\n";
                if (abs(b[i] - g[j]) <= 1)
                {
                    ans++;
                    mpp[j] = 1;
                    bo=true;
                }
            }
            if(bo)
            {
                break;
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        solve();
    }
}