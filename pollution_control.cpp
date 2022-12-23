#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(int n,int x,int y)
{
    //x =pollution of bus;
    // y=pollution of car
    //bus can carry at max 100 people car can carry at max 4 people;
    int ans=INT_MAX;
    for(int i=0;i<=n;i++)
    {
        int w=ceil((float(i))/4)*y;
        int z=ceil((float(n-i))/100)*x;
        // cout<<w<<" "<<z<<"\n";
        ans=min(ans,w+z);
    }
    return ans;
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
        int x,y;
        cin>>x>>y;
        cout<<solve(n,x,y)<<"\n";
    }
}