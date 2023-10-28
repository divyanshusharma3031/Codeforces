#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin >> s;
    int zi = -1;
    int oi = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zi =i;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            oi=i;
            break;
        }
    }
    if(zi==-1 || oi==-1)
    {
        cout<<"0\n";
        return 0;
    }
    if(zi<oi)
    {
        cout<<"0\n";
        return 0; 
    }
    int z=0;
    int o=0;
    for(int i=oi;i<=zi;i++)
    {
        if(s[i]=='0')
        {
            z++;
        }
        else
        {
            o++;
        }
    }
    cout<<min(z,o)<<"\n";
}