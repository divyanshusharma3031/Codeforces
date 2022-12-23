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
    ll s;
    cin>>s;
    vi arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int su=0;
    for(ll i=0;i<n;i++)
    {
        su+=arr[i];
    }
    if(s==su)
    {
        cout<<"0\n";
        return;
    }
    if(s>su)
    {
        cout<<"-1\n";
        return;
    }
    map<int,int> mpp;
    int a=0;
    for(int i=n-1;i>=0;i--)
    {
        a=a+arr[i];
        if(mpp.find(a)==mpp.end())
        {
            mpp[a]=n-i;
        }
    }
    int b=0;
    int req=su-s;
    int ans=mpp[req];
    for(int i=0;i<n;i++)
    {
        b+=arr[i];
        if(req>b && mpp[req-b])
        {
            ans=min(ans,mpp[req-b]+i+1);
        }
        if(b==req)
        {
            ans=min(ans,i+1);
        }
        
    }
    cout<<ans<<"\n";
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