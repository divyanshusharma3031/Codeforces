// template taken from Striver_79
// Remember you were also a novice when you started
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
#define int long long
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

// Function to convert a number
// from given base to decimal number
int toDeci(string str, int base)
{
    // Stores the length
    // of the string
    int len = str.size();

    // Initialize power of base
    int power = 1;

    // Initialize result
    int num = 0;

    // Decimal equivalent is str[len-1]*1
    // + str[len-2]*base + str[len-3]*(base^2) + ...
    for (int i = len - 1; i >= 0; i--)
    {

        // A digit in input number must
        // be less than number's base
        if (val(str[i]) >= base)
        {
            printf("Invalid Number");
            return -1;
        }

        // Update num
        num += val(str[i]) * power;

        // Update power
        power = power * base;
    }

    return num;
}

// Function to return equivalent
// character of a given value
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// Function to convert a given
// decimal number to a given base
string fromDeci(int base, int inputNum)
{
    // Store the result
    string res = "";

    // Repeatedly divide inputNum
    // by base and take remainder
    while (inputNum > 0)
    {

        // Update res
        res += reVal(inputNum % base);

        // Update inputNum
        inputNum /= base;
    }

    // Reverse the result
    reverse(res.begin(), res.end());

    return res;
}

// Function to convert a given number
// from a base to another base
string convertBase(string s, int a, int b)
{
    // Convert the number from
    // base A to decimal
    int num = toDeci(s, a);

    // Convert the number from
    // decimal to base B
    string ans = fromDeci(b, num);

    // Print the result
    return ans;
}
void solve()
{
    // Do not get stuck on a single approach for long, think of multiple ways
    ll n;
    cin >> n;
    string s=to_string(n);
    string ans=convertBase(s,10,9);
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]>'3')
        {
            ans[i]=ans[i]+1;
        }
    }
    cout<<ans<<"\n";
}
int32_t main()
{
    // hamare saath shree raghunath to kisi baat ki chinta nahi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}