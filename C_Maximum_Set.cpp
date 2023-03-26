#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
template<class T> 
using vec = vector<T>;
using vi = vec<int>;
using vl = vec<ll>;
using vd = vec<ld>;
using vvi = vec<vi>;
using vvl = vec<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vec<pi>;
using vpl = vec<pl>;
template<class T> 
using mxpq = priority_queue<T>;
template<class T> 
using mnpq = priority_queue<T, vec<T>, greater<T>>;
#define pb push_back
#define eb emplace_back
#define acc accumulate



#define MULTI_TESTS
// #define FLOAT_PRECISION 13



void solve() {
    int l, r;
    cin >> l >> r;

    int p = 0;
    ll tp = l;
    while (tp * 2 <= r) {
        p++;
        tp *= 2;
    }

    if (p == 0) {
        cout << "1 " << r - l + 1 << "\n";
        return;
    }

    cout << p + 1 << " ";

    // cout << p << ' ';

    // int st = 1, en = r;
    // int rq = 0;
    // while (st <= en) {
    //     int md = (st + en) / 2;
    //     tp = l;
    //     int cp = 1;
    //     while (tp * md <= r) {
    //         tp *= md;
    //         cp++;
    //     }
    //     if (cp < p) {
    //         en = md - 1;
    //     }
    //     else {
    //         rq = md;
    //         st = md + 1;
    //     }
    // }

    int st = l, en = r;
    int rq = l - 1;
    while (st <= en) {
        int md = (st + en) / 2;
        // cout << st << ' ' << md << ' ' << en << '\n';
        bool ok = true;
        tp = md;
        for (int i = 0; i < p; ++i) {
            tp *= 2;
            if (tp > r) {
                ok = false;
                break;
            }
        }
        if (ok) {
            rq = md;
            st = md + 1;
        }
        else {
            en = md - 1;
        }
    }

    // cout << rq << ' ';

    const ll mod = 998'244'353;
    ll ans = rq - l + 1;

    st = l, en = r;
    rq = l - 1;
    while (st <= en) {
        int md = (st + en) / 2;
        bool ok = true;
        tp = md;
        for (int i = 0; i < p; ++i) {
            tp *= 3;
            if (tp > r) {
                ok = false;
                break;
            }
        }
        if (ok) {
            rq = md;
            st = md + 1;
        }
        else {
            en = md - 1;
        }
    }

    // cout << rq << ' ';

    ans += rq - l + 1;
    ans %= mod;

    if (p >= 2) {
        st = l, en = r;
        rq = l - 1;
        while (st <= en) {
            int md = (st + en) / 2;
            bool ok = true;
            tp = md;
            tp *= 3;
            if (tp > r) {
                ok = false;
            }
            for (int i = 0; i < p - 1; ++i) {
                tp *= 2;
                if (tp > r) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                rq = md;
                st = md + 1;
            }
            else {
                en = md - 1;
            }
        }
        ans += 1LL * p * (rq - l + 1);
        ans %= mod;
        // cout << rq << ' ';
    }

    cout << ans << "\n";
};

void init() {
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    
    #ifdef FLOAT_PRECISION
        cout << fixed;
        cout.precision(FLOAT_PRECISION);
    #endif
    
    init();
    
    int numTests = 1;
    #ifdef MULTI_TESTS
        cin >> numTests;
    #endif
    for (int testNo = 1; testNo <= numTests; testNo++) {
        solve();
    }
    
    return 0;
}