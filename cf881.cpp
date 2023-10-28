class Solution
{
public:
#define int long long
    const int mod = 1e9 + 7;
    int dp[101][2][10][2];
    bool isSmaller(string &str1, string &str2)
    {
        // Calculate lengths of both string
        int n1 = str1.length(), n2 = str2.length();

        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;

        for (int i = 0; i < n1; i++)
            if (str1[i] < str2[i])
                return true;
            else if (str1[i] > str2[i])
                return false;

        return false;
    }

    // Function for find difference of larger numbers
    string findDiff(string &str1, string &str2)
    {
        // Before proceeding further, make sure str1
        // is not smaller
        if (isSmaller(str1, str2))
            swap(str1, str2);

        // Take an empty string for storing result
        string str = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();

        // Reverse both of strings
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        int carry = 0;

        // Run loop till small string length
        // and subtract digit of str1 to str2
        for (int i = 0; i < n2; i++)
        {
            // Do school mathematics, compute difference of
            // current digits

            int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

            // If subtraction is less than zero
            // we add then we add 10 into sub and
            // take carry as 1 for calculating next step
            if (sub < 0)
            {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str.push_back(sub + '0');
        }

        // subtract remaining digits of larger number
        for (int i = n2; i < n1; i++)
        {
            int sub = ((str1[i] - '0') - carry);

            // if the sub value is -ve, then make it positive
            if (sub < 0)
            {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str.push_back(sub + '0');
        }

        // reverse resultant string
        reverse(str.begin(), str.end());

        return str;
    }
    ll solve(string &s, ll tight = 1, ll idx = 0, ll prev = -1, ll zero = 1)
    {
        if (idx == s.size())
        {
            return !zero;
        }
        if (dp[tight][idx][prev + 1][zero] != -1)
            return dp[tight][idx][prev + 1][zero];
        ll limit = (tight ? s[idx] - '0' : 9);
        ll ans = 0;

        if (zero)
        {
            ans += solve(s, 0, idx + 1, -1, 1);
        }

        for (ll d = 0; d <= limit; d++)
        {
            ll newTight = (tight && d == s[idx] - '0');

            if (zero && d != 0)
            {

                ans += solve(s, newTight, idx + 1, d, false);
                ans %= mod;
            }
            else if (!zero)
            {
                if (abs(prev - d) == 1)
                {
                    ans += solve(s, newTight, idx + 1, d, false);
                    ans %= mod;
                }
            }
        }

        return dp[tight][idx][prev + 1][zero] = ans;
    }

    int countSteppingNumbers(string low, string high)
    {

        memset(dp, -1, sizeof dp);

        ll left = solve(low);

        memset(dp, -1, sizeof dp);

        ll right = solve(high);

        int ans = right - left;

        ans %= mod;
        ans += mod;
        ans %= mod;

        ll add = true;

        for (ll i = 1; i < low.size(); i++)
        {
            if (abs(low[i] - low[i - 1] != 1))
            {
                add = false;
            }
        }

        if (add)
            ans++;

        ans %= mod;

        return ans;
    }
};
#undef int