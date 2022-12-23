#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<long long> getbinary(long long n)
{
    vector<long long> ans;
    if (n == 0)
    {
        ans.push_back(0);
        return ans;
    }
    while (n > 0)
    {
        long long rem = n % 2;
        ans.push_back(rem);
        n = n / 2;
    }
    return ans;
}

// C++ program to convert binary to decimal
// when input is represented as binary string.
// Function to convert binary to decimal
long long binaryToDecimal(vector<long long> n)
{
    vector<long long> num = n;
    long long dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    long long base = 1;

    long long len = num.size();
    for (long long i = len - 1; i >= 0; i--)
    {
        if (num[i] == 1)
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}
long long bitReduction(vector<int> arr)
{
    int n=arr.size();   
    long long s = 0;
    for (long long i = 0; i < n; i++)
    {
        int temp=arr[i];
        arr[i]=arr[i]&(-arr[i]);
        s=s+arr[i];
    }
    return s;
}

int main()
{

    bitReduction({5,2,6,3,1});
    return 0;
}

// cppte
// 5,2,6,3,1