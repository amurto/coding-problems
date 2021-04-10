#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// 47 92
string solve()
{
    string str;
    cin >> str;
    int n = str.length();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int cur = str[i];
        if (cur == 92)
        {
            queue<int> q;
            while (!st.empty() && st.top() != 47)
            {
                q.push(st.top());
                st.pop();
            }
            st.pop();
            while (!q.empty())
            {
                st.push(q.front());
                q.pop();
            }
        }
        else
            st.push(cur);
    }
    string res = "";
    while (!st.empty())
    {
        res.pb(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}