// https://codeforces.com/contest/1204/problem/D2
// Kirk and a Binary String (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    string str;
    cin >> str;
    int n = str.length();
    stack<int> st;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
            st.push(i);
        else
        {
            if (!st.empty() && str[st.top()] == '1')
            {
                vis[st.top()] = vis[i] = true;
                st.pop();
            }
            else
                st.push(i);
        }
    }
    for (int i = 0; i < n; i++)
        if (!vis[i])
            str[i] = '0';
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}