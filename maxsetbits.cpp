#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define endl "\n"

typedef long long ll;

typedef vector<ll> vi;

void reverse(ll lo, ll hi, vector<ll> &arr)
{
    while (lo <= hi)
    {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}

bool palindrome(string s)
{
    ll i = 0;
    ll n = s.length() - 1;
    if (n == 0)
    {
        return false;
    }
    while (i <= n)
    {
        if (s[i] != s[n])
        {
            return false;
        }

        i++;
        n--;
    }
    return true;
}
ll GetLeftMostSetBit(ll n){
    ll pos = 0;
     
    while(n>0){
        pos++;
        n>>=1;
    }
     
    return pos;
}
 
ll TotalSetBitsFrom1ToN(ll n){
    ll leftMostSetBitInd = GetLeftMostSetBit(n);   
     
    ll totalRep, mod;
    ll nearestPow;
    ll totalSetBitCount = 0;
    ll addRemaining=0;
     
    ll curr=0; // denotes the number of set bits at index i
     
    //cout<<"leftMostSetBitInd: "<<leftMostSetBitInd<<endl;
     
    for(ll i=1; i<=leftMostSetBitInd; ++i){
        nearestPow = pow(2, i);
        if(nearestPow>n){
            ll lastPow = pow(2, i-1);
            mod = n%lastPow;
            totalSetBitCount += mod+1;
        }
        else{           
            if(i==1 && n%2==1){
                totalRep = (n+1)/nearestPow;
                mod = nearestPow%2;
                addRemaining =  0;
            }
            else{
                totalRep = n/nearestPow;
                mod = n%nearestPow;
                 
                if(mod >= (nearestPow/2)){
                    addRemaining = mod - (nearestPow/2) + 1;
                }else{
                    addRemaining = 0;
                }
            }
             
            curr = totalRep*(nearestPow/2) + addRemaining;
            totalSetBitCount += curr;
        }
        // debug output at each iteration
        //cout<<i<<" "<<nearestPow<<" "<<totalRep<<" "<<mod<<" "<<totalSetBitCount<<" "<<curr<<endl;
    }
     
    return totalSetBitCount;
}
void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin>>k;
    if(n==1)
    {
        ll x=__builtin_popcount(k);
        cout<<x<<"\n";
        return;
    }
    if(n>=k)
    {
        cout<<k<<"\n";
        return;
    }
    ll x=1;
    ll w=0;
    ll idx=-1;
    ll succ=-1;
    for(int i=1;i<32;i++)
    {
        x=pow(2,i)-1;
        w=x*n;
        if(w>=k)
        {
            succ=i;
            idx=i-1;
            break;
        }
    }
    if(w==n)
    {
        cout<<(n*(__builtin_popcount(x)))<<"\n";
        return;
    }
    ll p=pow(2,idx)-1;
    ll s=pow(2,succ)-1;
    x=ceil((k-n*p)/((s-p)/1.0));
    // cout<<x<<"\n";
    ll diff=s*x+p*(n-x)-k;
    cout<<(__builtin_popcount(s))*x+((__builtin_popcount(p))*(n-x)) -__builtin_popcount(diff)<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}