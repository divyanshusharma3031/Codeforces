#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
bool prime[90 * 1000000+1];
int primes[8000000];
int main()
{
    int t;
    cin >> t;
    memset(prime, 1, sizeof(prime));
    int n = 90 * 1000000+1;
    for (int i = 2; i * i < n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    int j=0;
    for(int i=2;i<n;i++)
    {
        if(primes[i] && j<8000000)
        {
            primes[j]=i;
            j++;
        }
    }
    while (t>0)
    {
        int k;
        cin>>k;
        cout<<primes[k-1]<<"\n";
        t--;
    }
    return 0;
}