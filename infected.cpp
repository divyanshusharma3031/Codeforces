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
    
    vector<int> adj[n+1];
    
    for(int i=0;i<n-1;i++)
    {
        int u;
        int v;
        cin>>u;
        cin>>v;
        adj[u].puah_back(v);
        adj[v].push_back(u);
    }


    if(n==2)
    {
        cout<<0<<"\n";
        return;
    }

    

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