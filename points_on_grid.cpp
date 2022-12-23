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
void solve(int d)
{
    if(d%2)
    {
        cout<<"-1\n";
        return;
    }
    int x1=0;
    int y1=d/2;
    int x2=d/2;
    int y2=0;
    int x3=d/2;
    int y3=d;
    int x4=d;
    int y4=d/2;
    cout<<x1<<" "<<y1<<"\n";
    cout<<x2<<" "<<y2<<"\n";
    cout<<x3<<" "<<y3<<"\n";
    cout<<x4<<" "<<y4<<"\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int d;
    cin>>d;
    solve(d);
}
