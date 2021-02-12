// https://codeforces.com/contest/56/problem/C
// Corporation Mail

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1005;

int solve()
{
    string str;
    cin >> str;
    int res = 0;
    vector<string> st;
    string name = "";
    for (char ch : str)
    {
        if (isupper(ch))
            name.pb(ch);
        else if (ch == ',')
            name = "";
        else if (ch == ':')
        {
            st.pb(name);
            name = "";
        }
        else
        {
            if (!name.empty())
                st.pb(name);
            name = st.back();
            st.pop_back();
            for (string s : st)
                res += (s == name);
            name = "";
        }
    }
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