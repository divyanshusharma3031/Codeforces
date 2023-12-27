#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define MOD (ll)(1E9+7)
int countDistinctColor(vector<string> &Domino)
{
    long long t=1;
    string s1=Domino[0];
    string s2=Domino[1];
    int n=s1.size();
    bool tok = true;
	for(int i=0;i<n;i++){
	  if(s1[i] == s2[i]) {
	    if(i==0) {
	      t*=3;
	      tok=true;
	      continue;
	    }
	    t *= tok?2:1;
	    t%=MOD;
	    tok = true;
	  } else {
	    if(i==0) {
	      t*=6;
	      tok=false;
	      i++;
	      continue;
	    }
	    i++;
	    t*= tok ? 2:3;
	    t%=MOD;
	    tok = false;
	  }
	}
    return t;
}
int main()
{
    vector<string> v={"baa","bcc"};
    cout<<countDistinctColor(v)<<"\n";
    return 0;
}