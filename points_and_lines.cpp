#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
        set<int> x;
        set<int> y;
        for(int i=0;i<n;i++)
        {
            int xi;
            int yi;
            cin>>xi;
            cin>>yi;
            x.insert(xi);
            y.insert(yi);
        }
        cout<<x.size()+y.size()<<"\n";
    }
}