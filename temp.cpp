#include <bits/stdc++.h>
using namespace std;
int main()
{
    // cp solutions
    int v;
    cin >> v;
    while (v--)
    {
        int n, m;
        cin >> n >> m;
        bool chk = false;
        string s, v;
        cin >> s >> v;
        for (char i = 'a'; i < 'f'; i++)
        {
            int k = 0;
            string s1(s.size(), 0);
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == '?')
                {
                    s1[j] = i;
                }
                else
                {
                    s1[j] = s[j];
                }
                if (s1[j] == v[k] and k < m)
                {
                    k++;
                }
            }
            if (k != m)
            {
                cout << s1 << endl;
                chk = true;
                break;
            }
        }
        if (!chk)
            cout << -1 << endl;
    }
}