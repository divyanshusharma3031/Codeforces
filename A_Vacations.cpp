// template taken from Striver_79
// Remember you were also a novice when you started
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure.
// The goal is to solve problems most efficiently not just barely
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
#define int long long
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;
void reverse(int lo, int hi, vector<int> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}
bool sign(int n)
{
    return n >= 0;
}
inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}
vi getbinary(int n)
{
    vector<int> ans;
    if (n == 0)
    {
        ans.push_back(0);
        return ans;
    }
    while (n > 0)
    {
        int rem = n % 2;
        ans.push_back(rem);
        n = n / 2;
    }
    return ans;
}
// ai equals 0, if on the i-th day of vacations the gym is closed and the contest is not carried out;
// ai equals 1, if on the i-th day of vacations the gym is closed, but the contest is carried out;
// ai equals 2, if on the i-th day of vacations the gym is open and the contest is not carried out;
// ai equals 3, if on the i-th day of vacations the gym is open and the contest is carried out.
int dp[101][4];
int solve(int idx,vector<int> &arr,int prev)
{
    int n=arr.size();
    if(idx==n)
    {
        return 0;
    }
    if(dp[idx][prev]!=-1)
    {
        return dp[idx][prev];
    }
    if(arr[idx]==0)
    {
        return dp[idx][prev]=solve(idx+1,arr,0);
    }
    else if(arr[idx]==1)
    {
        if(prev==1)
        {
            return dp[idx][prev]=solve(idx+1,arr,0);
        }
        return dp[idx][prev]=max(1+solve(idx+1,arr,1),solve(idx+1,arr,0));
    }
    else if(arr[idx]==2)
    {
        if(prev==2)
        {
            return dp[idx][prev]=solve(idx+1,arr,0);
        }
        return dp[idx][prev]=max(1+solve(idx+1,arr,2),solve(idx+1,arr,0));
    }
    if(prev==1)
    {
        return dp[idx][prev]=max(1+solve(idx+1,arr,2),solve(idx+1,arr,0));
    }
    else if(prev==2)
    {
        return dp[idx][prev]=max(1+solve(idx+1,arr,1),solve(idx+1,arr,0));
    }
    return dp[idx][prev]=max({1+solve(idx+1,arr,2),1+solve(idx+1,arr,1),solve(idx+1,arr,0)});
}
void test()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    // ai->0 : gym closed and contest not 
    // ai->1: gym closed and contest 
    // ai->2: gym open and contest not
    // ai->3: gym open and contest
    ll n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    memset(dp,-1,sizeof(dp));
    if(arr[0]==0)
    {
        ans=solve(1,arr,0);//0->nothing
    }
    else if(arr[0]==1)
    {
        ans=max(1+solve(1,arr,1),solve(1,arr,0));//1->give contest
    }
    else if(arr[0]==2)
    {
        ans=max(1+solve(1,arr,2),solve(1,arr,0));//2->go gym
    }
    else
    {
        ans=max({1+solve(1,arr,2),1+solve(1,arr,1),solve(1,arr,0)});
    }
    cout<<n-ans<<"\n";
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        test();
    }
    return 0;
}