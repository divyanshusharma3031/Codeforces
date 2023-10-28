// template taken from Striver_79
// Remember you were also a novice when you started
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
#define int long long
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    string s;
    cin >> s;
    vector<int> v;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
        {
            c++;
        }
    }
    if (c == 0)
    {
        if (k == 0)
            cout << 0 << "\n";
        else
            cout << 2 * k - 1 << "\n";
        return;
    }

    int ws = 0;
    for (int i = 0; i < n;)
    {
        if (s[i] == 'W')
        {
            int j = i + 1;
            while (j < n && s[j] == 'W')
            {
                j++;
            }
            ws++;
            i = j;
        }
        else
        {
            i++;
        }
    }
    vector<int> losing_streaks;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            if (i == 0 or s[i - 1] == 'W')
                losing_streaks.push_back(0);
            losing_streaks.back()++;
        }
    }
    if ((c + k) >= n)
    {
        cout << 2 * (n)-1 << "\n";
        return;
    }
    int ans = 2 * (c + k);
    if (s[0] == 'L')
    {
        losing_streaks[0] = 1e9;
    }
    if (s[n - 1] == 'L')
    {
        losing_streaks.back() = 1e9;
    }
    sort(losing_streaks.begin(), losing_streaks.end());
    for (auto it : losing_streaks)
    {
        if (it > k)
        {
            break;
        }
        k -= it;
        ws--;
    }
    cout << ans - ws << "\n";
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// int c = 0;
// vector<int> pref(n + 1, 0);
// for (int i = 0; i < n; i++)
// {
//     pref[i] = c;
//     if (s[i] == 'W')
//     {
//         c++;
//     }
// }
// vi suff(n + 1, 0);
// c = 0;
// for (int i = n - 1; i >= 0; i--)
// {
//     suff[i] = c;
//     if (s[i] == 'W')
//     {
//         c++;
//     }
// }
// deque<int> dq;
// int i = -1;
// int j = 0;
// int ans=0;
// dq.push_back(-1);
// while (j < n)
// {
//     if (s[j] == 'L')
//     {
//         k--;
//         dq.push_back(j);
//         if (k < 0)
//         {
//             dq.pop_front();
//             i = dq.front();
//             k++;
//         }
//     }
//     // cout<<i<<" "<<j<<"\n";
//     int x = 2 * (j - i) - 1;
//     if ((i + 1) != j)
//     {
//         x = x + pref[i + 1] + suff[j];
//     }
//     else
//     {
//         x = x + pref[i + 1];
//     }
//     ans=max(ans,x);
//     j++;
// }
// cout<<ans<<"\n";