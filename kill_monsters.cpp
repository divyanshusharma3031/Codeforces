#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll hc;
        ll dc;
        ll hm;
        ll dm;
        ll k;
        ll w;
        ll a;
        cin >> hc >> dc;
        cin >> hm >> dm;
        cin >> k >> w >> a;
        ll x = ceil((db(hc)) / dm);
        ll y = ceil((db(hm) / dc));
        if (x >= y)
        {
            // cout<<x<<" "<<y<<"\n";
            cout << "YES"
                 << "\n";
        }
        else
        {
            if(k==0)
            {
                cout<<"NO\n";
                continue;
            }
            bool b = false;

            for (ll i = 0; i <= k; i++)
            {
                ll nhc = hc + i * a;
                ll nwc = dc + (k - i) * w;
                x = ceil((db(nhc)) / dm);
                y = ceil((db(hm) / nwc));
                // cout<<x<<" "<<y<<"\n";
                if (x >= y)
                {
                    b = true;
                    cout << "YES\n";
                    break;
                }
            }
            if (!b)
            {
                cout << "NO\n";
            }
        }
    }
}
// 1
// 25 4
// 12 20
// 1 1 10