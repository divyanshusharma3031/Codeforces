#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> a;
    for(int i=0;i<=10000000;i++)
    {
        a.push_back(i);
        cout<<i<<" inserted\n";
    }
    return 0;
}