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

void reverse(int lo, int hi, vector<int> &arr)
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
    int i = 0;
    int n = s.length() - 1;
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

void solve()
{
  ll n;
  cin>>n;
  vector<string> arr(2*n);
  map<string,int> mpp;
  char c=0;
  for(int i=0;i<2*n;i++)
  {
      cin>>arr[i];
      
  }
  for(int i=0;i<2*n;i++)
  {
      for(auto x:arr[i]){
          c=c^x;
      }
  }
  string s;
  cin>>s;
  for(auto x:s)
  {
      c^=x;
  }
  cout<<c<<"\n";
//   s is the final string we have to chose a sequence which will give it.


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}