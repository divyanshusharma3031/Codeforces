#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{
    if((n%7)==0)
    {
        cout<<n<<"\n";
        return;
    }
    vector<int> arr;
    int n1=n;
    while(n)
    {
        arr.push_back(n%10);
        n=n/10;
    }
    reverse(arr.begin(),arr.end());
    int rem=n1%7;
    int w=n1%10;
    int y=w-rem;
    if(y>0)
    {
        for(int i=0;i<arr.size()-1;i++)
        {
            cout<<arr[i];
        }
        cout<<y<<"\n";
        return;
    }
    n1=n1+7-rem;
    cout<<n1<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        solve(n);
    }
}