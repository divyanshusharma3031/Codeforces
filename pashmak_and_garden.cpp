#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define endl "\n"

#define forr(i, a, n) for (long long i = a; i < n; i++)

#define all(x) x.begin(), x.end()

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
    ll x1;

    ll x2;

    ll y1;

    ll y2;

    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2)
    {
        // means they are adjacent.
        int y3 = y2;
        int y4 = y1;
        int d = 0;
        if (y2 > y1)
        {
            d = y2 - y1;
            int x3 = x1 + d;
            cout << x3 << " " << y3 << " " << x3 << " " << y4 << "\n";
        }
        else
        {
            d = y1 - y2;
            int x3 = x1 + d;
            cout << x3 << " " << y3 << " " << x3 << " " << y4 << "\n";
        }
        return;
    }
    if (y1 == y2)
    {
        // means they are adjacent.
        int x3 = x1;
        int x4 = x2;
        int d = 0;
        if (x2 > x1)
        {
            d = x2 - x1;
            int y3 = y1 + d;
            cout << x3 << " " << y3 << " " << x4 << " " << y3 << "\n";
        }
        else
        {
            d = x1 - x2;
            int y3 = y1 + d;
            cout << x3 << " " << y3 << " " << x4 << " " << y3 << "\n";
        }
        return;
    }

    // they are diagonal trees

    int y3 = y1;
    int x3 = x2;
    int x4 = x1;
    int y4 = y2;
    if (x1 != x2 && y1 != y2 && abs(x1 - x2) != abs(y1 - y2))
        cout << -1 << endl;
    else
    {
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
    }
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