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
        ll r;
        ll b;
        cin >> r >> b;
        if (b == 1)
        {
            for (int i = 1; i <= r / 2; i++)
            {
                cout <<"R";
            }
            cout<<"B"<<"";
            int rem=r/2.0;
            for(int i=1;i<=rem;i++)
            {
                cout<<"R";
            }
            cout<<"\n";
            continue;
        }
        int gr = r / b;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (k == gr)
            {
                cout << "B";
                k = 0;
            }
            else
            {
                cout << "R";
                k++;
            }
        }
        cout << "\n";
    }
}