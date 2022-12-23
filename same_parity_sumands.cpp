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

    ll k;
    cin >> k;

    vi ans;
    if (n % 2 == 0)
    {
        if (k % 2 == 0)
        {
            int x = k - 1;
            int i = 0;
            while (i < x)
            {
                ans.push_back(1);
                n = n - 1;
                i++;
            }
            if (n <= 0)
            {
                cout << "NO\n";
                return;
            }
            ans.push_back(n);
            cout << "YES\n";
            for (int j = 0; j < ans.size(); j++)
            {
                cout << ans[j] << " ";
            }
            cout << "\n";
            return;
        }
        else
        {
            int x = k - 1;
            int i = 0;
            while (i < x)
            {
                ans.push_back(2);
                n = n - 2;
                i++;
            }
            if (n <= 0)
            {
                cout << "NO\n";
                return;
            }
            ans.push_back(n);
            cout << "YES\n";
            for (int j = 0; j < ans.size(); j++)
            {
                cout << ans[j] << " ";
            }
            cout << "\n";
            return;
        }
    }
    if (k % 2 == 0)
    {
        cout << "NO\n";
        return;
    }
    int x = k - 1;
    int i = 0;
    while (i < x)
    {
        ans.push_back(1);
        n = n - 1;
        i++;
    }
    if (n <= 0)
    {
        cout << "NO\n";
        return;
    }
    ans.push_back(n);
    cout << "YES\n";
    for (int j = 0; j < ans.size(); j++)
    {
        cout << ans[j] << " ";
    }
    cout << "\n";
    return;
}
int main()
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