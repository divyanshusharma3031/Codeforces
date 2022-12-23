#include<bits/stdc++.h>
using namespace std;
int solve(int n)
{
    // c*(c+1)=2*n;
    // c*c +c-2n=0;
    // c=-1+sqrt(1+4*n);
    long long x=n;
    double c=-1 + sqrt(1+8*x);
    c=c/2;
    return floor(c);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
}