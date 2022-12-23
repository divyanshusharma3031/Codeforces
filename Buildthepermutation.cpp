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
    ll a;
    ll b;
    cin >> a >> b;
    // a maximas
    // b minimas

    // 1 2 3 4 5 6
    // 1 2 3 4 5
    int pm = (n + 1) / 2 - 1;
    int pmini = (n + 1) / 2 - 1;
    if (b > pm || a > pmini)
    {
        cout << "-1\n";
        return;
    }
    vector<int> arr(n, 0);
    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = i;
    }
    if (abs(b - a) > 1)
    {
        cout << "-1\n";
        return;
    }
    if (b == a)
    {
        int x=n/2-1;
        if(n%2 && x<b)
        {
            cout<<"-1\n";
            return;
        }
        for (int i = 1; i < n;)
        {
            if (b > 0)
            {
                swap(arr[i], arr[i + 1]);
                b--;
                a--;
                i += 2;
            }
            else
            {
                break;
            }
        }
    }
    else if (b > a)
    {
        for (int i = 0; i < n-1;)
        {
            if (b == 0)
            {
                break;
            }
            swap(arr[i], arr[i + 1]);
            i += 2;
            b--;
            
        }
    }
    else
    {
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < n-1;)
        {
            if (a == 0)
            {
                break;
            }
            swap(arr[i], arr[i + 1]);
            i += 2;
            a--;
            
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    // 1 2 3 4 5 6
    // 2 1 4 3 5 6
    // 6 5 4 3 2 1
    // 5 6 3 4 2 1
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