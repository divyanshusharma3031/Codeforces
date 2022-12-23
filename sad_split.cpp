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

void solve(int n)
{
    int x=n%10;
    n=n/10;
    if((x%2)==0)
    {
        while(n)
        {
            int rem=n%10;
            if((rem%2)==0)
            {
                cout<<"YES\n";
                return;
            }
            n=n/10;
        }
    }
    else
    {
        while(n)
        {
            int rem=n%10;
            if((rem%2))
            {
                cout<<"YES\n";
                return;
            }
            n=n/10;
        }
    }
    cout<<"NO\n";
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
        solve(n);
    }
}
