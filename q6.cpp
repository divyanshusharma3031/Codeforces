#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int q;
    int d, k, n;
    string x;
    for (int m = 0; m < t; m++)
    {
        cin>>q;
        int n1 = 1, n2 = 1;
        int ca1 = 1, ca2 = 1;
        bool flag = 0;
        for (int i = 0; i < q; i++)
        {
            cin>>d>>k>>x;
            if (flag)
            {
                cout<<"YES\n";
                continue;
            }
            n = x.size();
            if (d == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (x[j] == 'a')
                    ca1 += k;
                    n1 += k;
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (x[j] == 'a')
                    ca2 += k;
                    else
                    {
                        cout<<"YES\n";
                        flag = 1;
                        break;
                    }
                    n2 += k;
                }
            }
            if (flag)
            continue;
            if (n1 >= n2)
            {
                cout<<"NO\n";
            }
            else if (n2 > n1 && n1 != ca1)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
        }
    }
    return 0;
}