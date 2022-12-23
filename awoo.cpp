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
    int n;
    cin>>n;
    string s;
    string t;
    cin>>s>>t;
    if(s==t)
    {
        cout<<"YES\n";
        return;
    }
    vi c(3,0);
    for(int i=0;i<s.length();i++)
    {
        c[s[i]-'a']++;
    }
    for(int i=0;i<s.length();i++)
    {
        c[t[i]-'a']--;
    }
    if(c[0]!=0 || c[1]!=0 || c[2]!=0)
    {
        cout<<"NO\n";
        return;
    }
    string s1;
    string t1;
    for(int i=0;i<n;i++)
    {
        if(s[i]!='b')
        {
            s1+=s[i];
        }
        if(t[i]!='b')
        {
            t1+=t[i];
        }
    }
    if(s1!=t1)
    {
        cout<<"NO\n";
        return;
    }
    vector<int> cidx1;
    vector<int> cidx2;
    vector<int> aidx1;
    vector<int> aidx2;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='c')
        {
            cidx1.push_back(i);
        }
        if(t[i]=='c')
        {
            cidx2.push_back(i);
        }
        if(s[i]=='a')
        {
            aidx1.push_back(i);
        }
        if(t[i]=='a')
        {
            aidx2.push_back(i);
        }
    }
    for(int i=0;i<cidx1.size();i++)
    {
        if(cidx1[i]<cidx2[i])
        {
            cout<<"NO\n";
            return;
        }
    }
    
    for(int i=0;i<aidx1.size();i++)
    {
        if(aidx1[i]>aidx2[i])
        {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";

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