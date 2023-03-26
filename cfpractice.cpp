int maxSubArray(vector<int> &arr)
{
    ll ans = INT_MIN;
    ll temp = 0;
    for (auto i : arr)
    {
        temp = temp + i;
        if (ans < temp)
        {
            ans = temp;
        }
        if (temp < 0)
        {
            temp = 0;
        }
    }
    return ans;
}