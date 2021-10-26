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

class op
{
public:
    int l, r, v1, v2;
    op() {}
    op(int l, int r, int v1, int v2) : l(l), r(r), v1(v1), v2(v2) {}
    bool operator<(const op &other) const
    {
        if (v2 == other.v2)
            return v1 < other.v1;
        return v2 > other.v2;
    }
};

void dfs(vector<bool> &vis, vector<int> &p, vector<int> &nodes, int cur)
{
    vis[cur] = true;
    nodes.pb(cur);
    if (!vis[p[cur]])
        dfs(vis, p, nodes, p[cur]);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), v(n + 1), pos(n + 1), nxt(n + 1), prev(n + 1);
    vector<bool> vis(n + 1);
    vector<pii> ops, swaps;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<int> p_st = p, v_st = v;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> nodes;
            dfs(vis, p, nodes, i);
            int sz = (int)nodes.size();
            if (sz > 1)
            {
                int c = pos[i], t = i;
                for (int j = 1; j < sz; j++)
                {
                    ops.pb({c, t});
                    t = p[t];
                }
                ll sum = 0;
                for (int x : nodes)
                    sum += 1ll * v[pos[x]];
                if (sum >= 2 * (sz - 1))
                {
                    for (int i = 1; i < sz; i++)
                    {
                        nxt[nodes[i - 1]] = nodes[i];
                        prev[nodes[i]] = nodes[i - 1];
                    }
                    nxt[nodes[sz - 1]] = nodes[0];
                    prev[nodes[0]] = nodes[sz - 1];
                    priority_queue<op> pq;
                    for (int e : nodes)
                        pq.push(op(e, nxt[e], v[pos[e]], v[pos[nxt[e]]]));
                    set<int> st(nodes.begin(), nodes.end());
                    while (st.size() > 1)
                    {
                        op cur = pq.top();
                        pq.pop();
                        if (st.find(cur.l) != st.end() && st.find(cur.r) != st.end() && v[pos[cur.l]] == cur.v1 && v[pos[cur.r]] == cur.v2)
                        {
                            st.erase(cur.l);
                            v[pos[cur.l]]--, v[pos[cur.r]]--;
                            swaps.pb({pos[cur.l], pos[cur.r]});
                            swap(p[pos[cur.l]], p[pos[cur.r]]);
                            swap(pos[cur.l], pos[cur.r]);
                            nxt[prev[cur.l]] = cur.r;
                            prev[cur.r] = prev[cur.l];
                            pq.push(op(prev[cur.r], cur.r, v[pos[prev[cur.r]]], v[pos[cur.r]]));
                            pq.push(op(cur.r, nxt[cur.r], v[pos[cur.r]], v[pos[nxt[cur.r]]]));
                        }
                    }
                }
            }
        }
    }
    int m1 = (int)swaps.size(), m2 = (int)ops.size();
    if (m1 == m2)
    {
        cout << "Alice\n";
        swap(ops, swaps);
    }
    else
        cout << "Bob\n";
    cout << (int)ops.size() << "\n";
    for (pii x : ops)
        cout << x.first << " " << x.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}