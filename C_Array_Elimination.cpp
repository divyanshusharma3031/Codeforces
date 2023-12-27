#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define ft first
#define sd second
#define pb push_back
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vll;
 
#define dbg if(1)
 
 
const int MOD = 1e9+7;
const int INF = 1e9;
const int N = 300001;
int n;
 
void solve(){
    int n;cin>>n;
 
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
 
    int bits[32];
 
    for (int i=0;i<32;i++) bits[i]=0;
 
    for (int i=0;i<n;i++){
        for (int j=0;j<32;j++){
            bits[j]+=((a[i]&(1<<j))!=0);
        }
    }
 
    vi ans;
    for (int i=1;i<=n;i++){
        // cout<<"h "<<i<<" "<<bits[i]<<endl;
        bool poss = true;
        for (int j=0;j<32;j++){
            if (bits[j]%i!=0) {
                poss = false;
                break;
            }
        }
        if (poss) ans.push_back(i);
 
    }
 
    for(auto x:ans) cout<<x<<" ";
 
 
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t=1;
    cin>>t;
 
    while(t--){
        solve();
        cout<<endl;
    }
}