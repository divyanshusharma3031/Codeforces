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

void solve(vector<ll> &arr, ll n)
{
    vector<int> ans(n, -1);
    map<int, int> mpp;
    ll maxele=INT_MIN;
    int fnn=-1;
    vector<int> x;
    vector<int> y;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]!=-1 && (arr[i] > (i + 1) || maxele>arr[i]))
        {
            cout << "-1\n";
            return;
        }
        maxele=max(maxele,arr[i]);
        if(mpp[arr[i]]==1)
        {
            arr[i]=-1;
        }
        if(arr[i]!=-1)
        {
            x.push_back(arr[i]);
            if(fnn==-1)
            {
                fnn=i;
            }
        }
        mpp[arr[i]] = 1;
    }
    for (int i = 0; i < n+1; i++)
    {
        if(mpp[i]!=1)
        {
            y.push_back(i);
        }
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    vector<int> new_arr(n,0);
    for(int i=0;i<n;i++)
    {
        if(i==fnn || arr[i]==-1)
        {
            new_arr[i]=y.back();
            y.pop_back();
        }
        else
        {
            new_arr[i]=x.back();
            x.pop_back();
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<new_arr[i]<<" ";
        /* code */
    }
    cout<<"\n";
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}