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
    vector<int> a;
    vector<int> b;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    string s;
    cin>>s;
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='B')
        {
            if(arr[i]<=0)
            {
                cout<<"NO\n";
                return;
            }
            b.push_back(arr[i]);
        }
        else
        {
            if(arr[i]>n)
            {
                cout<<"NO\n";
                return;
            }
            a.push_back(arr[i]);
        }
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end());
    bool ok=true;
    set<int> se;
    for(int i=1;i<=n;i++)
    {
        se.insert(i);
    }
    for(int i=0;i<b.size();i++)
    {
        int x=*se.begin();
       
        if(b[i]>=x)
        {
            se.erase(x);
        }
        else
        {
            // cout<<x<<" "<<b[i]<<"\n";
            ok=false;
        }
    }
    for(int i=0;i<a.size();i++)
    {
        int x=*se.rbegin();
        if(a[i]<=x)
        {
            se.erase(x);
        }
        else
        {
            // cout<<x<<" "<<a[i]<<"\n";
            ok=false;
        }
    }
    if(ok)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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