// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=6100
// 8078 - Bracket Sequence

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool open(char ch)
{
    return (ch == '(' || ch == '{' || ch == '[' || ch == '<');
}

bool close(char ch)
{
    return (ch == ')' || ch == '}' || ch == ']' || ch == '>');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unordered_map<char, char> alt;
    vector<char> op = {'(', '{', '[', '<'}, cl = {')', '}', ']', '>'};
    for (int i = 0; i < 4; i++)
    {
        alt[op[i]] = cl[i];
        alt[cl[i]] = op[i];
    }
    int t;
    cin >> t;
    for (int tc=1; tc<=t; tc++)
    {
        string str;
        stack<pair<char, int>> st;
        cin >> str;
        int n = str.length();
        vector<int> sc(n + 1);
        for (int i = n - 1; i >= 0; i--)
        {
            if (open(str[i]))
            {
                if (st.empty() || str[i] != alt[st.top().first]) {
                    while (!st.empty())
                        st.pop();
                    continue;
                }
                sc[i] += st.top().second - i + 1 + sc[st.top().second + 1];
                st.pop();
            }
            else
            {
                st.push({str[i], i});
            }
        }
        cout << "Case " << tc << ":\n";
        for (int i=0; i<n; i++)
            cout << sc[i] << "\n";
    }
    return 0;
}