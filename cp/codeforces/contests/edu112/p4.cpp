#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, m;
    string str;
    cin >> n >> m >> str;
    vector<pii> q(m);
    vector<int> res(m);
    for (int i = 0; i < m; i++)
    {
        cin >> q[i].first >> q[i].second;
        res[i] = q[i].second - q[i].first + 1;
    }
    string st = "abc";
    do
    {
        string tmp;
        for (int i = 0; i < n; i++)
            tmp.pb(st[i % 3]);
        d(tmp);
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++)
            pre[i + 1] = (str[i] != tmp[i]);
        for (int i = 1; i <= n; i++)
            pre[i] += pre[i - 1];
        for (int i = 0; i < m; i++)
            res[i] = min(res[i], pre[q[i].second] - pre[q[i].first-1]);
    } while (next_permutation(st.begin(), st.end()));
    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}