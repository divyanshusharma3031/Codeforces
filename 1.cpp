#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r=0;
    int c=0;
    string str;
    cin>>str;
    set<int> s;
    int n=str.length();
    while(r<str.size())
    {
        if(s.find(str[r])!=s.end())
        {
            c++;
            s.clear();
        }
        s.insert(str[r]);
        r++;
    }
    cout<<c+1<<"\n";
    return 0;
}