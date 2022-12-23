#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void reverse(int lo,int hi,vector<int> &arr)
{
    while(lo<=hi)
    {
        swap(arr[lo],arr[hi]);
        lo++;
        hi--;
    }
}
vector<int> ans(1000,0);
void compute()
{
    ans[0]=1e9;
    int i=1;
    while(i<1000)
    {
        ans[i]=floor(double(ans[i-1])/3);
        if(ans[i]==0)
        {
            break;
        }
        i++;
    }
    // cout<<i<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin>>n;
        compute();
        if(n<=19)
        {
            cout<<"YES\n";
            for(int i=0;i<n;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}
