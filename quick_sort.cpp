#include <bits/stdc++.h>
using namespace std;


//kode for qwikesort

int parti(int arr[],int lo,int hi)
{
    int i=lo;
    int j=hi;
    int pivot=arr[lo];
    while(i<j)
    {
        do
        {
            /* code */
            i++;
        } while (arr[i]<=pivot);
        do
        {
            /* code */
            j--;
        } while (arr[j]>pivot);
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[lo],arr[j]);
    return j;
}


void Quicksort(int arr[],int lo,int hi)
{
    if(lo<hi)
    {
        int j=parti(arr,lo,hi);

        Quicksort(arr,lo,j);

        Quicksort(arr,j+1,hi);

    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n+1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr[n]=INT_MAX;
    Quicksort(arr, 0, n );
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}