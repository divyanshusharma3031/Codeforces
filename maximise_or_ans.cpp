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

void solve(vector<int> arr, ll n)
{
    priority_queue<int> odd;
    priority_queue<int> even;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2)
        {
            odd.push(arr[i]);
        }
        else
        {
            even.push(arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll x1;
        if (!odd.empty() && !even.empty())
        {
            if (i % 2 == 0)
            {
                x1 = odd.top() | even.top();
                odd.pop();
                even.pop();
            }
            else
            {
                x1 = odd.top() & even.top();
                odd.pop();
                even.pop();
            }
            if (x1 % 2)
            {
                odd.push(x1);
            }
            else
            {
                even.push(x1);
            }
            // cout<<x1<<" ";
            continue;
        }
        if (!odd.empty())
        {
            ll a1 = odd.top();
            ll a2 = odd.top();
            if (i % 2 == 0)
            {
                x1 = a1 | a2;
            }
            else
            {
                x1 = a1 & a2;
            }
            if (x1 % 2)
            {
                odd.push(x1);
            }
            else
            {
                even.push(x1);
            }
        }
        else
        {
            ll a1 = even.top();
            ll a2 = even.top();
            if (i % 2 == 0)
            {
                x1 = a1 | a2;
            }
            else
            {
                x1 = a1 & a2;
            }
            if (x1 % 2)
            {
                odd.push(x1);
            }
            else
            {
                even.push(x1);
            }
        }
        // cout<<x1<<" ";
        
    }
    if(!even.empty())
    {
        cout<<even.top()<<"\n";
        return;
    }
    cout<<odd.top()<<"\n";
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
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        solve(arr, n);
    }
}