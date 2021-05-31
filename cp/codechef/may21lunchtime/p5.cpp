#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5;
vector<int> g[N];
int token[N];

ll dfs(stack<int> &st, int cur, int last, int d)
{
    ll dis = 0;
    if (token[cur] == 1)
        st.push(d);
    for (int e : g[cur])
        if (e != last)
            dis += dfs(st, e, cur, d + 1);
    int sz = st.size();
    if (sz == d)
    {
        dis += 1ll * (st.top() - d);
        st.pop();
    }
    return dis;
}

ll solve()
{
    int n, p;
    string str;
    cin >> n >> str;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
        token[i] = (str[i - 1] - '0');
    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        g[p].pb(i);
        g[i].pb(p);
    }
    stack<int> st;
    return dfs(st, 1, 1, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}