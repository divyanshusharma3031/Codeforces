#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define FORd(i, a, b) for (int i = (b) - 1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; --i)
#define trav(a, x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 998'244'353;
const char nl = '\n';
const int MX = 100001;

vector<ll> facts(200'001);

ll power(ll num, ll p)
{
    ll ans = 1;
    while (p) {
        if (p & 1) ans = ans * num % MOD;
        num = num * num % MOD;
        p >>= 1;
    }

    return ans;
}

void calc_facts()
{
    facts[0] = 1;
    FOR(i, 1, 200'001) {
        facts[i] = facts[i - 1] * i % MOD;
        // cout << facts[i] << nl;
    }
}

void solve()
{
    int n; cin >> n;
    vi a(n); trav(e, a) cin >> e;

    sort(all(a));
    reverse(all(a));
    if (a[0] == a[1]) {
        // perm_all
        cout << facts[n] << nl;
    } else if (a[0] == a[1] + 1) {
        int x = 0;
        trav(e, a) {
            if (e == a[1])
                x++;
        }

        ll ans = facts[n];
        for (int i = n - 1; i >= x; --i) {
            ll curAns = 1;
            curAns = curAns * facts[i] % MOD;
            curAns = curAns * facts[n - x - 1] % MOD;
            curAns = curAns * power(facts[i - x], MOD - 2) % MOD;

            ans = (ans - curAns) % MOD;
            if (ans < 0) ans += MOD;
        }

        cout << ans << nl;
    } else {
        // 0
        cout << 0 << nl;
    }
}

void input()
{
    
}

void output()
{
    
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    calc_facts();

    int TC = 1;
    cin >> TC;
    while (TC--) {
        input();
        solve();
        output();
    }
    
    return 0;
}