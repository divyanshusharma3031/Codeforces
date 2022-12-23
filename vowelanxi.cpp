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

void reverse(int lo, int hi, string &arr)
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
    

    string s;
    cin>>s;

    set<int> se;
    se.insert('a');
    se.insert('e');
    se.insert('i');
    se.insert('o');
    se.insert('u');

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        if(se.find(s[i])!=se.end())
        {
            v.push_back({0,i-1});
        }
    }
    int a=0;
    if(v.size()==0)
    {
        cout<<s<<"\n";
        return;
    }
    int j=n-1;
    while(j>=0 && se.find(s[j])==se.end())
    {
        j--;
    }
    j--;
    int idx=j;
    int st=0;
    int end=j;
    int d=0;
    char ans[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=s[i];
    }
    while(idx>=0)
    {
        string t;
        while(idx>=0)
        {
            if(se.find(s[idx])!=se.end())
            {
                t.push_back(s[idx]);
                idx--;
                break;
            }
            else
            {
                t.push_back(s[idx]);
            }
            idx--;
        }
        if(d%2)
        {
            for(auto i:t)
            {
                ans[end--]=i;
            }
        }
        else
        {
            for(auto i:t)
            {
                ans[end--]=i;
            }
        }
        // cout<<ans<<"\n";
        d=d+1;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<"";
    }
    cout<<"\n";
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