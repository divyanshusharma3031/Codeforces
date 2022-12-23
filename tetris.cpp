#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> fullJustify(vector<string> &words, int L)
{
    vector<string> res;
    for (int i = 0, k, l; i < words.size(); i += k)
    {
        for (k = l = 0; i + k < words.size() && l + words[i + k].size() <= L - k; k++)
        {
            l += words[i + k].size();
        }
        string tmp = words[i];
        for (int j = 0; j < k - 1; j++)
        {
            if (i + k >= words.size())
                tmp += " ";
            else
                tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
            tmp += words[i + j + 1];
        }
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
    }
    string s(res[0].size(), '*');
    for (int i = 0; i < res.size(); i++)
    {
        res[i] = "*" + res[i];
        res[i] = res[i] + "*";
    }

    res.push_back(s);
    vector<string> f;
    f.push_back(s);
    for (int i = 0; i < res.size(); i++)
    {
        f.push_back(res[i]);
    }
    return f;
}
vector<string> solution(vector<vector<string>> &paragraphs, int k)
{
    vector<string> ans;
    for (int w = 0; w < paragraphs.size(); w++)
    {
        vector<string> words = paragraphs[w];
        for (int i = 0, k, l; i < words.size(); i += k)
        {
            for (k = l = 0; i + k < words.size() && l + words[i + k].size() <= L - k; k++)
            {
                l += words[i + k].size();
            }
            string tmp = words[i];
            for (int j = 0; j < k - 1; j++)
            {
                if (i + k >= words.size())
                    tmp += " ";
                else
                    tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
                tmp += words[i + j + 1];
            }
            tmp += string(L - tmp.size(), ' ');
            ans.push_back(tmp);
        }
    }
    string s(ans[0].size(), '*');
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = "*" + ans[i];
        ans[i] = ans[i] + "*";
    }

    ans.push_back(s);
    vector<string> f;
    f.push_back(s);
    for (int i = 0; i < ans.size(); i++)
    {
        f.push_back(ans[i]);
    }
    return f;
}
int main()
{

    return 0;
}