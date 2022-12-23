#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'deleteProducts' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ids
 *  2. INTEGER m
 */

int deleteProducts(vector<int> arr, int m)
{
    map<int, int> mpp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    int x = mpp.size();
    vector<pair<int,int>> v;
    for (auto i : mpp)
    {
        v.push_back({i.second,i.first});
    }
    sort(v.begin(),v.end());
    int i=0;
    while(i<v.size())
    {
        if(v[i].first<=m)
        {
            m=m-v[i].first-1;
            x--;
        }
        i++;
    }
    return x;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    cout << deleteProducts(arr, m) << "\n";
}