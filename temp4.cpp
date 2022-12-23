#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, c, q, i, j, k;
    string a, b;
    cin >> t;

    for (; t--;)
    {
        cin >> n >> c >> q;

        a = "1";
        cin >> b;

        a = a + b;

        ll l[c + 1], r[c + 1], len[c + 1];

        len[0] = n;

        for (i = 1; i <= c; i++)
        {
            cin >> l[i] >> r[i];
            len[i] = len[i - 1] + r[i] - l[i] + 1;
        }
        for (int i = 0; i <= c; i++)
        {
            cout << len[i] << " ";
        }
        for (; q--;)
        {
            cin >> k;

            i = c;

            while (i != 0)
            {
                if (len[i - 1] >= k)
                {
                    i--;
                }
                else
                {
                    k = k - len[i - 1];
                    k = l[i] + k - 1;
                    i--;
                }
                // cout<<k<<" "<<len[i]<<"\n";
            }
            cout << a[k] << "\n";
        }
    }
}