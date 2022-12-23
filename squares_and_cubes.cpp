#include <bits/stdc++.h>
using namespace std;
int sac(int n)
{
    set<long long> s;
    for(int i=1;i<=(n);i++)
    {
        long long sq=i*i;
        long long c=sq*i;
        if(sq>n)
        {
            break;
        }
        if(sq<=n)
        {
            s.insert(sq);
        }
        if(c<=n)
        {
            s.insert(c);
        }
    }
    return s.size();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << sac(n) << '\n';
    }
    return 0;
}