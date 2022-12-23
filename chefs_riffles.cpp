#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ll long long
// vector<int>(int s,int e,int p)
// {
//     vector<int> v;
//     for(int i=s,i<e;i=i+p)
//     {
//         v.push_back
//     }
// }
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n, 0);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        vector<int> aux1;
        vector<int> aux2;
        vector<int> b = arr;
        vector<vector<int>> dp;
        dp.push_back(arr);
        int i = 0;
        while (i < n)
        {
            if (i % 2)
            {
                aux1.push_back(arr[i]);
            }
            else
            {
                aux2.push_back(arr[i]);
            }
            i++;
        }
        i = 0;
        int j = 0;
        while (j < aux2.size())
        {
            arr[i] = aux2[j];
            i++;
            j++;
        }
        j = 0;
        while (j < aux1.size())
        {
            arr[i] = aux1[j];
            j++;
            i++;
        }
        dp.push_back(arr);
        while (b != arr)
        {
            vector<int> aux1;
            vector<int> aux2;
            int i = 0;
            while (i < n)
            {
                if (i % 2)
                {
                    aux1.push_back(arr[i]);
                }
                else
                {
                    aux2.push_back(arr[i]);
                }
                i++;
            }
            i = 0;
            int j = 0;
            while (j < aux2.size())
            {
                arr[i] = aux2[j];
                i++;
                j++;
            }
            j = 0;
            while (j < aux1.size())
            {
                arr[i] = aux1[j];
                j++;
                i++;
            }
            if(b==arr)
            {
                break;
            }
            dp.push_back(arr);
        }
        vector<int> ans=dp[((k)%dp.size())];
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}