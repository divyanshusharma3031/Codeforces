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

void solve(vector<ll> &arr,ll n)
{
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(i+1);
    }

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
        deque<int> a;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }
        int arr[n+1]={0};
        for(int i=n;i>0;i--)
        {
            while(a.back()!=i)
            {
                a.push_back(a.front());
                a.pop_front();
                arr[i]++;
            }
            a.pop_back();
        }
        for(int i=1;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
}