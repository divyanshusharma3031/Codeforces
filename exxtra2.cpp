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

int deleteProducts(vector<int> ids, int m) {
    map<int,int> mpp;
    int n =ids.size();
    for (int i=0;i<n;i++)
    {
      mpp[ids[i]]++;
    }
    int x=mpp.size();
    vector<pair<int,int>>v;
    for(auto i: mpp)
    {
      v.push_back({i.second,i.first});
      
    }
    sort(v.begin(),v.end());
    int i=0;
    while(i<v.size())
    {
      if(v[i].first<=m)
      {
        m=v[i].first-1;
        x--;
      }
      i++;
    }
    return x;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ids_count_temp;
    getline(cin, ids_count_temp);

    int ids_count = stoi(ltrim(rtrim(ids_count_temp)));

    vector<int> ids(ids_count);

    for (int i = 0; i < ids_count; i++) {
        string ids_item_temp;
        getline(cin, ids_item_temp);

        int ids_item = stoi(ltrim(rtrim(ids_item_temp)));

        ids[i] = ids_item;
    }

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));
    cout<<m<<"\n";

    int result = deleteProducts(ids, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}