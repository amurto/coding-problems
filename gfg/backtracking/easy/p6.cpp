// All permutations of string
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void PP(string &str, vector<string> &ans, int cur)
{
    if (cur == str.length() - 1)
        ans.push_back(str);
    else
    {
        for (int i = cur; i < str.length(); i++)
        {
            swap(str[cur], str[i]);
            PP(str, ans, cur + 1);
            swap(str[i], str[cur]);
        }
    }
}

int main()
{
    string str;
    cin >> str;
    vector<string> ans;
    PP(str, ans, 0);
    for (string v : ans)
        cout << v << "\n";
    return 0;
}