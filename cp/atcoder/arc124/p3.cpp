#ifdef use_debug
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

void dfs(set<pii> &st, vector<int> &a, vector<int> &b, int cur, int p, int q)
{
    if (cur == a.size())
    {
        st.insert({p, q});
        return;
    }
    dfs(st, a, b, cur + 1, __gcd(p, a[cur]), __gcd(q, b[cur]));
    dfs(st, a, b, cur + 1, __gcd(p, b[cur]), __gcd(q, a[cur]));
}

ll get_lcm(int x1, int x2)
{
    return (x1 * 1ll * x2) / __gcd(x1, x2);
}

ll solve()
{
    int n;
    ll res = 1;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    vector<int> tmpA, tmpB;
    set<pii> st1, st2;
    for (int i = 0; i < n / 2; i++)
    {
        tmpA.pb(a[i]);
        tmpB.pb(b[i]);
    }
    dfs(st1, tmpA, tmpB, 0, 0, 0);
    tmpA.clear();
    tmpB.clear();
    for (int i = n / 2; i < n; i++)
    {
        tmpA.pb(a[i]);
        tmpB.pb(b[i]);
    }
    dfs(st2, tmpA, tmpB, 0, 0, 0);
    for (pii p : st1)
    {
        for (pii q : st2)
        {
            res = max(res, get_lcm(__gcd(p.first, q.first), __gcd(p.second, q.second)));
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