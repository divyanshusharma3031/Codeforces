#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

typedef vector<ll> vi;

void reverse(int lo, int hi, vector<int> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}

bool palindrome(string s)
{
    int i = 0;
    int n = s.length() - 1;
    if (n == 0)
    {
        return false;
    }
    while (i <= n)
    {
        if (s[i] != s[n])
        {
            return false;
        }

        i++;
        n--;
    }
    return true;
}

#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (a[n - 2] > a[n - 1]) {
            cout << -1 << endl;
        } else {
            if (a[n - 1] < 0) {
                if (is_sorted(a.begin(), a.end())) {
                    cout << 0 << endl;
                } else {
                    cout << -1 << endl;
                }
            } else {
                cout << n - 2 << endl;
                for (int i = 1; i <= n - 2; ++i) {
                    cout << i << ' ' << n - 1 << ' ' << n << endl;
                }
            }
        }
    }
}