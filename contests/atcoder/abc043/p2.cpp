#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    stack<char> st;
    for (char ch : s)
    {
        if (ch == 'B')
        {
            if (!st.empty())
                st.pop();
        }
        else
            st.push(ch);
    }
    string res = "";
    while (!st.empty())
    {
        res.pb(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
    return 0;
}