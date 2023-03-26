#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#else
#define debug(x...)
#endif
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll            long long int
#define double        long double
#define INF           9e18

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1e9 + 7;
const ll N = 2e5 + 5;

//credits gfg
ll andOperator2(ll a, ll b) {
      ll shiftcount = 0;
      while(a != b and a > 0) {
          shiftcount++;
          a = a >> 1;
          b = b >> 1;
    }
      return int64_t(a << shiftcount);
}

ll check(ll mid, ll n, ll x) {
    ll val = andOperator2(n, mid);
    if(val == x) {
        return 0;
    }
    else if(val < x) {
        return 1;
    }
    else {
        return 2;
    }
}

void solve(int test_case) {
    ll n, x;
    cin >> n >> x;
    ll low = n, high = 5e18;

    if(x > n) {
        cout << "-1\n";
        return;
    }

    ll ans = -1;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        ll val = check(mid, n, x);
        if(val == 0) {
            ans = mid;
            high = mid - 1;
        }
        else if(val == 1) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    clock_t z = clock();

    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        solve(tc);
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}