#include <bits/stdc++.h>
using namespace std;
unordered_map<unsigned long long, pair<unsigned long long, unsigned long long>> mpp;

unsigned long long reverseBits(unsigned long long n)
{
    unsigned long long rev = 0;

    // traversing bits of 'n' from the right
    while (n > 0)
    {
        // bitwise left shift
        // 'rev' by 1
        rev <<= 1;

        // if current bit is '1'
        if (n & 1 == 1)
            rev ^= 1;

        // bitwise right shift
        // 'n' by 1
        n >>= 1;
    }

    // required number
    return rev;
}
void solve(unsigned long long x, unsigned long long y)
{
    if (x == y)
    {
        cout << "YES" << '\n';
        return;
    }
    else if (x < y)
    {
        if (mpp[x].first == 0)
        {
            mpp[x].first = 1;
            x = ((x << 1) | 1);
            x = reverseBits(x);
            cout << x << " 1" << '\n';
            solve(x, y);
        }
        else if (mpp[x].second == 0)
        {
            mpp[x].second = 1;
            x = ((x << 1));
            x = reverseBits(x);
            cout << x << " 2" << '\n';
            solve(x, y);
        }
        else
        {
            cout << "NO" << '\n';
            return;
        }
    }
    else
    {
        if (mpp[x].first == 0)
        {
            mpp[x].first = 1;
            x = ((x << 1));
            x = reverseBits(x);
            cout << x << " 3" << '\n';

            solve(x, y);
        }
        else if (mpp[x].second == 0)
        {
            mpp[x].second = 1;
            x = ((x << 1) | 1);
            x = reverseBits(x);
            // cout<<x<<'\n';
            cout << x << " 4" << '\n';
            solve(x, y);
        }
        else
        {
            cout << "NO" << '\n';
            return;
        }
    }
}
int main()
{
    unsigned long long x;
    unsigned long long y;
    cin >> x;
    cin >> y;
    solve(x, y);
    return 0;
}