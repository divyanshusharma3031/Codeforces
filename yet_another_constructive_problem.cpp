#include <bits/stdc++.h>
using namespace std;
void solve(long long x)
{

    long long a = 0;
    long long w = 0;
    for (int i = 0; i <=32; i++)
    {
        if ((x & (1 << i)) == 0)
        {
            w = x | (1 << i);
            break;
        }
    }
    cout << a << " " << x << " " << w << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        solve(x);
    }
}