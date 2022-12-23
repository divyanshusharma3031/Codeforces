/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,i,even=0,odd=0,ans,sol=0;
        int b=0;
        cin>>n;
        long long a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2==0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        if(a[0]%2==a[n-1]%2)
        {
            if(a[0]%2==0)
            {
                even--;
                cout<<even<<"\n";
            }
            else
            {
                odd--;
                cout<<odd<<"\n";
            }
        }
        else
        {
            long long op[n],same=0;
            op[0]=0;
            for(i=1;i<n;i++)
            {
                if(a[i]%2!=a[0]%2)
                {
                    op[i]=op[i-1]+1;
                }
                else
                {
                    op[i]=op[i-1];
                }
            }
            ans=op[n-1];
            for(i=1;i<n;i++)
            {
                if(a[0]%2==a[i]%2)
                {
                    same++;
                    ans=min(ans,op[n-1]-op[i]+same);
                }
            }
            cout<<ans<<"\n";
            
        }
    }
    return 0;
}