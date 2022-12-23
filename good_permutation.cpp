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

void solve(int n)
{
    if (n == 1)
    {
        cout << "-1\n";
        return;
    }
    if (n % 2 == 0)
    {
        for (int i = n; i > 0; i--)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    else
    {
        if(n==5)
        {
            cout<<"3 5 1 2 4\n";
            return;
        }
        else if(n>5)
        {
            cout<<"3 5 1 2 4 ";
            vector<int> arr;
            for(int i=6;i<=n;i++)
            {
                arr.push_back(i);
            }
            for(int i=0;i<arr.size()-1;)
            {
                swap(arr[i],arr[i+1]);
                i+=2;
            }
            for(int i=0;i<arr.size();i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
            return;
        }
    }
    cout<<"-1\n";
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
        solve(n);
    }
}