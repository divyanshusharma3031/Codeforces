#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <math.h>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll p = 0; p < n; p++)
        {
            cin >> arr[p];
        }

        if (n == 0)
        {
            cout << "-1" << endl;
            continue;
        }

        sort(arr, arr + n);

        set<int> s2;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            s2.insert(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (c == 0)
            {
                c++;
            }
            s2.erase(arr[i]);
        }
        ll mex = *(s2.begin());

        if (mex == 1)
        {
            cout << "-1" << endl;
            continue;
        }

        if (mex == 0)
        {
            cout << (arr[0] - 1) << endl;
            continue;
        }
        set<int> s;
        vector<int> aux;
        for (ll i = 0; i < n; i++)
        {
            s.insert(arr[i]);
        }

        for (auto it : s)
        {
            aux.push_back(it);
        }

        ll count = 1;
        ll ans = 0;

        ll req = mex - 1;

        for (ll i = 0; i < aux.size(); i++)
        {
            ll x=arr[i-1]+1;
            ll y=arr[i];
            if (x!=y)
            {
                if (count >= (req))
                {
                    ans++;
                }
                count = 1;
            }
            else
            {
                count++;
            }
        }
        if (count >= (req))
        {
            ans++;
        }
        cout << (ans - 1) << "\n";
        // 0 1 2 4 5 6 10
    }
    return 0;
}