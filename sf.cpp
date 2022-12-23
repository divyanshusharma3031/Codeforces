#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> vect(n, vector<ll>(m));
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            cin >> vect[i][j];
        }
    }
    if(m==1) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    vector<vector<ll>> copy;
    copy = vect;

    for(ll i=0; i<n; i++) {
        sort(copy[i].begin(), copy[i].end());
    }   
    // for(auto it: copy) {
    //     for(auto jt: it) {
    //         cout << jt;
    //     }
    // }
    map<ll, ll> mp;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            if(vect[i][j] != copy[i][j]) {
                // cout << j << " ";
                mp[j]++;
            }
        }
    }
    if(mp.size() > 2) {
        cout << -1 << endl;
        return;
    }
    if(mp.size() == 0) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    vector<ll> temp;
    for(auto it: mp) {
        temp.push_back(it.first);
    }
    for(ll i=0; i<n; i++) {
        swap(vect[i][temp[0]], vect[i][temp[1]]);
    }
    bool flag = true;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            if(vect[i][j] != copy[i][j]) {
                flag = false;
                break;
            }
        }
    }
    if(!flag) {
        cout << -1 << endl;
    }
    else {
        sort(temp.begin(),temp.end());
        cout << temp[0]+1 << " " << temp[1]+1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    clock_t z = clock();

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}