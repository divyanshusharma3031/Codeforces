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
    ll k;
    cin>>k;
    string a;
    cin>>a;
    string b;
    cin>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0;
    int j=0;
    int k1=0;
    int k2=0;
    string c="";
    while(i<n && j<m)
    {
        if(a[i]<b[j] && k1!=k)
        {
            c+=a[i];
            k1++;
            k2=0;
            i++;
        }
        else if(k2!=k)
        {
            c+=b[j];
            k2++;
            k1=0;
            j++;
        }
        else
        {
            c+=a[i];
            i++;
            k1++;
            k2=0;
        }
    }
    cout<<c<<"\n";
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