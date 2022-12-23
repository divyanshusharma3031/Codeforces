#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int q;
    cin >> n >> q;
    string s;
    cin >> s;
    char f = 'a';
    int w = 0;
    int op = 0;
    for (int i = 0; i < n; i++)
    {
        // cout<<f<<"\n";
        if (s[i] == f)
        {
            w++;
            if (w == 3)
            {
                op++;
                w = 0;
                f = 'a';
            }
            else
                f++;
        }
        else
        {
            f = 'a';
            if (s[i] == 'a')
            {
                w = 1;
                f++;
            }
            else
                w = 0;
        }
    }
    if (w == 3)
    {
        op++;
    }
    while (q--)
    {
        int pos;
        cin >> pos;
        char x;
        cin >> x;
        char e = s[pos - 1];
        s[pos - 1] = x;
        // cout<<s<<"\n";
        if ((pos - 3) >= 0)
        {
            if (e != x && s[pos - 1] == 'c' && s[pos - 2] == 'b' && s[pos - 3] == 'a')
            {
                op++;
            }
            else
            {
                op--;
            }
        }
        if ((pos + 3) >= 0)
        {
            if (e != x && s[pos + 1] == 'c' && s[pos ] == 'b' && s[pos - 1] == 'a')
            {
                op++;
            }
            else
            {
                op--;
            }
        }
        cout<<op<<"\n";
    }
}