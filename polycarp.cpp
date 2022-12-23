#include<iostream>
#include<vector>
using namespace std;
void polycrap(int arr[],int n)
{
    vector<int> ans;
    ans.push_back(arr[0]);
    ans.push_back(arr[1]);
    int x=arr[0];
    int y=arr[1];
    int z=arr[n-1]-x-y;
    ans.push_back(z);
    for(int i=0;i<3;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int arr[7];
        for(int i=0;i<7;i++)
        {
            cin>>arr[i];
        }
        polycrap(arr,7);
    }
    return 0;
}