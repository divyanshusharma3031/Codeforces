#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define endl "\n"

#define int long long

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
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> b=arr;
    sort(b.begin(),b.end());
    vector<int> pref(n,0);
    pref[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=pref[i-1]+arr[i];
    }
    vector<int> pref2(n,0);
    pref2[0]=b[0];
    for(int i=1;i<n;i++)
    {
        pref2[i]=pref2[i-1]+b[i];
    }
    int m;
    cin>>m;
    while(m--)
    {
        int t;
        cin>>t;
        int l;
        int r;
        cin>>l>>r;
        if(t==1)
        {
            if(l==1)
            {
                cout<<pref[r-1]<<"\n";
            }
            else
            {
                cout<<pref[r-1]-pref[l-2]<<"\n";
            }
            
        }
        else
        {
            if(l==1)
            {
                cout<<pref2[r-1]<<"\n";
            }
            else
            {
                cout<<pref2[r-1]-pref2[l-2]<<"\n";
            }
           
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--)
    {
        solve();
    }
}