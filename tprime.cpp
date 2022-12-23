#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
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
bool sign(int n)
{
    return n >= 0;
}
inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}
vi getbinary(int n)
{
    vector<int> ans;
    if (n == 0)
    {
        ans.push_back(0);
        return ans;
    }
    while (n > 0)
    {
        int rem = n % 2;
        ans.push_back(rem);
        n = n / 2;
    }
    return ans;
}
map<int,int> mpp;
int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}
void solve()
{
    ll n;
    cin >> n;
    double y=sqrt(n);
    int z=y;
    if(y!=z)
    {
        cout<<"NO\n";
        return;
    }
    if(mpp[y])
    {
        if(mpp[y]%2)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        return;
    }
    int x=countDivisors(y);
    if(x==2)
    {
        mpp[y]=1;
        cout<<"YES\n";
        return;
    }
    mpp[y]=2;
    cout<<"NO\n";
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}