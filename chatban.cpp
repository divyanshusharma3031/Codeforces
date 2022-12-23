#include<bits/stdc++.h>
using namespace std;
using ll=long long int;

void solve()
{
  ll k ,x; cin>>k>>x;
  ll l= 1,r = 2*k - 1;
  ll ans = -1;
  
  while(l <= r){
      ll mid = l +(r - l)/2;
      ll lhs = (mid *(mid + 1))/2;
      if(mid >= k){
          lhs -= (mid * mid + k*k +  mid*(1-2*k) - k);
      }
      if(lhs == x){
          ans = mid; break;
      }
      else if(lhs < x){
          l = mid + 1;
      }
      else{
          ans = mid;
          r = mid - 1;
      }
  }
  if(ans == -1){
      cout<<(2*k - 1)<<"\n"; return;
  }
  cout<<ans<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}

