#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

void solve(ll a,ll b,ll c,ll x)
{
    vector<ll> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(x);

    sort(v.begin(),v.end());

    ll p=v[3];

    ll s=v[2];

    ll d;
    
    ll div;


    if(v[0]<0)
    {
        d=v[0];
        div=v[1];
    }

    else
    {
        d=v[1];
        div=v[0];
    }

    if(((s+d)%2)==0)
    {
        ll a=(s+d)/2;

        ll b=p/a;

        if((a/b==div && (a-b)==d) || ((b/a)==div && (b-a)==d))
        {
            if(a<b)
            {
                cout<<a<<" "<<b<<"\n";
            }
            else
            {
                cout<<b<<" "<<a<<"\n";
            }
            return;
        }
    }
    else if((p+d)%2==0)
    {
        ll a=(p+d)/2;

        ll b=p/a;

        if((a/b==div && (a-b)==d) || ((b/a)==div && (b-a)==d))
        {
            if(a<b)
            {
                cout<<a<<" "<<b<<"\n";
            }
            else
            {
                cout<<b<<" "<<a<<"\n";
            }
            return;
        }
    }
    cout<<"-1"<<" -1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        solve(a,b,c,d);
    }
}
