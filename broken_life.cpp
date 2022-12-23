#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>
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

bool isSubSequence(string str1, string str2, int m, int n)
{
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;
    return (j == m);
}

void solve()
{
    ll n;
    
    ll m;
    
    cin>>n>>m;

    string s;

    string a;

    cin>>s>>a;

    if(isSubSequence(a,s,m,n))
    {
        cout<<"-1\n";
        return;
    }

    set<char> se;
    se.insert('a');
    se.insert('b');
    se.insert('c');
    se.insert('d');
    se.insert('e');

    for(int i=0;i<m;i++)
    {
        se.erase(a[i]);
    }

    if(!se.empty())
    {
        char x=*se.begin();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                s[i]=x;
            }
        }
        cout<<s<<"\n";
        return;
    }

    int j=0;

    for(int i=0;i<n;i++)
    {
        if(j<m && s[i]==a[j])
        {
            j++;
        }
        if(s[i]=='?')
        {
            switch (a[j])
            {
                case 'a':
                    s[i]='b';
                    break;
                case 'b':
                    s[i]='c';
                    break;
                case 'c':
                    s[i]='d';
                    break;
                case 'd':
                    s[i]='e';
                    break;
                case 'e':
                    s[i]='a';
                    break;
                
            }
        }
    }
    cout<<s<<"\n";
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