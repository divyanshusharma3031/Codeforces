
#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

bool f(ll a[], ll tonnykakr, ll n)
{

    ll captainmarvel = 0;
    for (int i = 0; i < tonnykakr; i++)
        captainmarvel += a[i];

    ll mx = 0;
    for (int i = tonnykakr; i < n; i++)
        mx = max(a[i], mx);

    ll lele = 0;
    for (int i = tonnykakr; i < n; i++)
        lele += abs(a[i] - mx);

    if (captainmarvel >= lele)
        return true;

    return false;
}

ll ans(ll a[], ll n)
{

    ll LLLLLLLLLLLLL = 0, HHHHHHHH = n;
    ll ans = 0;
    while (HHHHHHHH >= LLLLLLLLLLLLL)
    {
        ll IKKKK = (LLLLLLLLLLLLL + HHHHHHHH) / 2;
        if (f(a, IKKKK, n))
        {
            HHHHHHHH = IKKKK - 1;
            ans = IKKKK;
        }
        else
        {
            LLLLLLLLLLLLL = IKKKK + 1;
        }
    }
    return ans;
}

int main()
{
    int te;
    cin >> te;
    while (te--)
    {

        ll n;
        cin >> n;
        ll arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        ll kks1 = ans(arr, n);
        reverse(arr, arr + n);
        ll kks = ans(arr, n);
        ll sup = min(kks1, kks);
        cout << sup << endl;
    }
}