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

    char c;

    cin >> c;

    string s;

    cin >> s;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            cnt++;
        }
    }

    if (cnt == n)
    {
        cout << "0" << endl;
        return;
    }

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != c)
        {
            v.push_back(i + 1);
        }
    }

    int o = 0;
    int e = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2)
        {
            o++;
        }
        else
        {
            e++;
        }
    }
    int x = n;
    if (n % 2 == 0)
    {
        x--;
    }
    if (e == 0)
    {
        cout << "1\n";
        cout << "2\n";
    }
    else if (o == 0)
    {
        cout << "1\n";
        cout << x << "\n";
    }
    else
    {
        
        for(int i=1;i<=n;i++)
        {
            bool ok=true;
            for(int j=i;j<=n;j++)
            {
                ok=(ok)&(s[j-1]==c);
                j+=(i-1);
            }
            if(ok)
            {
                cout<<"1\n";
                cout<<i<<"\n";
                return;
            }
        }
        cout << "2\n";
        cout << "2 " << x << "\n";
    }
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