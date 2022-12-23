#include <bits/stdc++.h>
using namespace std;
void intsub(int arr[], int n)
{
    int mn=arr[0];
    int mx=arr[0];
    int idxmin=0;
    int idxmax=0;
    for(int i=0;i<n;i++)
    {
        if(mx<arr[i])
        {
            mx=arr[i];
            idxmax=i;
        }
        if(mn>arr[i])
        {
            mn=arr[i];
            idxmin=i;
        }
          
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        intsub(arr, n);
    }
}
//difference of max and min of subarray should be greater than the size of subarray.