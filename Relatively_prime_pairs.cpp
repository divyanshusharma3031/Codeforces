#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void primes(long long l,long long r)
{
    vector<pair<long long,long long>> ans;
    long long n=(r-l+1)/2;
    long long a=l;
    for(long long i=0;i<n;i++)
    {
        ans.push_back({a,a+1});
        a+=2;
    }
    cout<<"YES\n";
    for(long long i=0;i<n;i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    return;
}
int main()
{
    long long l;
    long long r;
    cin>>l>>r;
    primes(l,r);    
    return 0;
}