#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

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

void solve()
{
    int n;
    cin>>n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    vector<int> v1;
    
    vector<int> v2;

    int i=0;

    int j=arr.size()-1;

    while(i<j)
    {
        v1.push_back(arr[i]);
        v2.push_back(arr[j]);
        i++;
        j--;
    }
    int x=arr[arr.size()/2];
    j=0;
    for(int i=0;i<v1.size();i++)
    {
        arr[j]=v1[i];
        arr[j+1]=v2[i];
        j+=2;
    }
    if(arr.size()%2)
    {
        arr[arr.size()-1]=x;
    }
    long long ans=0;

    for(int i=0;i<n;i++)
    {
        ans=ans+abs(arr[i]-arr[(i+1)%n]);
    }

    cout<<ans<<"\n";
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