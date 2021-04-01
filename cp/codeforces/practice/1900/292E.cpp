// https://codeforces.com/contest/292/problem/E
// Copying Data

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct node
{
    int op = 0, idx = 0; // identity
    node() {}
    node(int opr, int id)
    {
        op = opr;
        idx = id;
    }
    void merge(const node &l, const node &r)
    {
        if (l.op + r.op == 0)
        {
            idx = 0;
            return;
        }
        idx = (l.op > r.op) ? l.idx : r.idx;
        op = max(l.op, r.op);
    }
};

template <typename node>
struct segtree
{
    int len;
    vector<node> t;
    node identity_element;
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
        identity_element = node();
    }

    node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &id)
    {
        if (id > tr || id < tl)
            return identity_element;
        if (tl >= id && tr <= id)
            return t[v];
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, id), b = query(v << 1 | 1, tm + 1, tr, id), ans;
        ans.merge(a, b);
        ans.merge(ans, node(t[v].op, t[v].idx + id - tl));
        return ans;
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, int op, int x, int y)
    {
        if (l > tr || r < tl)
            return;
        if (tl >= l && tr <= r)
        {
            t[v].op = op;
            t[v].idx = tl - y + x;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, op, x, y);
        rupd(v << 1 | 1, tm + 1, tr, l, r, op, x, y);
    }

public:
    node query(const int32_t &id)
    {
        return query(1, 0, len - 1, id);
    }
    void rupd(const int32_t &l, const int32_t &r, int op, int x, int y)
    {
        rupd(1, 0, len - 1, l, r, op, x, y);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, x, y, k;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    segtree<node> s(n);
    for (int q = 1; q <= m; q++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x >> y >> k;
            s.rupd(y - 1, y + k - 2, q, x, y - 1);
        }
        else
        {
            cin >> x;
            x--;
            node res = s.query(x);
            if (res.op == 0)
                cout << b[x] << "\n";
            else
                cout << a[res.idx - 1] << "\n";
        }
    }
    return 0;
}