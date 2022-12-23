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
    ll m;
    cin>>m;

    vector<string> arr;

    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        arr.push_back(s);
    }

    vector<int> x;//jaha jaha blacks hai
    vector<int> y;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='B')
            {
                x.push_back(i+1);
                y.push_back(j+1);
            }
        }
    }
    int mn=INT_MAX;
    int xi=-1;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=0;j<x.size();j++)
        {
            ans=ans+abs(x[j]-i);
        }
        cout<<ans<<" "<<i<<"\n";
        if(mn>ans)
        {
            xi=i;
            mn=min(mn,ans);
        }
    }
    mn=INT_MAX;
    int yi=-1;
    for(int i=1;i<=m;i++)
    {
        int ans=0;
        for(int j=0;j<y.size();j++)
        {
            ans=ans+abs(y[j]-i);
        }
        cout<<ans<<" "<<i<<"\n";
        if(mn>ans)
        {
            yi=i;
            mn=min(mn,ans);
        }
    }
    cout<<xi<<" "<<yi<<"\n";
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