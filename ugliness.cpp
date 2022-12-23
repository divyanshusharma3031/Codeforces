#include<bits/stdc++.h>
using namespace std;
int mindiff(int arr[],int n)
{
    int s=0;
    for(int i=0;i<n;i++)
    {
        s+=arr[i];
    }
    //  agar sum n se divide ho sakta hai toh 0 aayga beacause of equal distribution otherwise 1 aayga
    if(s%n)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<mindiff(arr,n)<<"\n";
    }
    return 0;
}