#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void solveWordWrap(int n, string words, int k)
{
    // initialize total cost
    int c=0;
    vector<int> arr;
    
    for(int i=0;i<=words.size();)
    {
        if(i==words.size() || words[i]==' ')
        {
            while(i<n && words[i]==' ')
            {
                i++;
            }
            arr.push_back(c);
            c=0;
            if(i==words.size())
            {
                break;
            }
        }
        else
        {
            i++;
            c++;
        }
    }
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    n=arr.size();
    int total_cost = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // size of window left after the current element
        int size = k - 1 - arr[i];
        // cost of current line
        int sum = k - arr[i];
        while (size >= 0)
        {
            size = size - arr[i + 1] - 1;
            // breaks immidiately
            if (size < 0)
            {
                break;
            }
            sum = sum - arr[i] - 1;
            i++;
        }
        // add current cost to total cost
        total_cost = total_cost + (sum);
    }
    // print the total cost
    cout << total_cost;
}
int main()
{
    solveWordWrap(10,"aaa bb cc ddddd",6);
    return 0;
}
