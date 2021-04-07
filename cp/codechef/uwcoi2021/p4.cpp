#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct node
{
    ll v = 0; // identity
    node() {}
    node(ll val)
    {
        v = val;
    }
    void merge(const node &l, const node &r)
    {
        v = l.v + r.v;
    }
};

struct update
{
    ll a = 0, d = 0;
    int l = 0;
    update() {}
    update(ll first_term, ll diff, int first_idx)
    {
        a = first_term;
        d = diff;
        l = first_idx;
    }

    void fix(const int32_t &tl, const int32_t &tr)
    {
        a += 1ll * (tl - l) * d;
        l = tl;
    }
    // combine the current update with the other update
    void combine(update &other, const int32_t &tl, const int32_t &tr)
    {
        a += other.a;
        d += other.d;
        l = tl;
    }
    // store the correct information in the node x
    void apply(node &x, const int32_t &tl, const int32_t &tr)
    {
        ll diff = 1ll * (tr - tl);
        x.v += ((diff + 1) * (2 * a + diff * d)) / 2;
    }
};

template <typename node, typename update>
struct segtree
{
    int len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }

    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (!lazy[v])
            return;
        int32_t tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, u[v]);
        apply(v << 1 | 1, tm + 1, tr, u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }

    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd)
    {
        upd.fix(tl, tr);
        if (tl != tr)
        {
            lazy[v] = 1;
            u[v].combine(upd, tl, tr);
        }
        upd.apply(t[v], tl, tr);
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v].v = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
            return identity_element;
        if (tl >= l && tr <= r)
            return t[v];
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const update &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            apply(v, tl, tr, upd);
            return;
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, upd);
        rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const update &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x1, y1, x2, y2, sum = 0;
    int k;
    cin >> n >> m >> k;
    segtree<node, update> s(m);
    for (int i = 0; i < k; i++)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        x1--;
        y1--;
        x2--;
        y2--;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        sum += 2 * (y2 - y1 + x2 - x1);
        ll cost = abs(y2 - y1), t = abs(y2 - y1) / 4;
        s.rupd(x1, x2, update(cost, 0, x1));
        if (t >= 1)
        {
            if (x1 > 0)
                s.rupd(max(0ll, x1 - t), x1 - 1, update(cost - (x1 - max(0ll, x1 - t)) * 4, 4, max(0ll, x1 - t)));
            if (x2 < m - 1)
                s.rupd(x2 + 1, min(m * 1ll - 1, x2 + t), update(cost - 4, -4, x2 + 1));
        }
    }
    ll res = sum;
    for (int i = 0; i < m; i++)
    {
        ll v = s.query(i, i).v;
        res = min(res, sum - v);
    }
    cout << res << "\n";
    return 0;
}

// Solution 2 without using segment tree (Offline Updates)

// Range Update Arithmetic Progression Offline
void updateLeft(vector<ll> &dev, vector<ll> &diff, int l, int r, ll a, ll d)
{
    dev[r] += a;
    dev[l - 1] -= (a + (r - l) * 1ll * d);
    diff[r] += d;
    diff[l] -= d;
}

// Range Update Arithmetic Progression Offline
void updateRight(vector<ll> &dev, vector<ll> &diff, int l, int r, ll a, ll d)
{
    dev[l] += a;
    dev[r + 1] -= (a + (r - l) * 1ll * d);
    diff[l] += d;
    diff[r] -= d;
}

void solve()
{
    ll n, m, x1, y1, x2, y2, sum = 0;
    int k;
    cin >> n >> m >> k;
    vector<vector<ll>> left(2, vector<ll>(m + 5)), right(2, vector<ll>(m + 5));
    for (int i = 0; i < k; i++)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        ll cost = abs(y2 - y1), t = abs(y2 - y1) / 4;
        sum += 2 * (y2 - y1 + x2 - x1);
        updateRight(right[0], right[1], x1, x2, cost, 0);
        if (t >= 1)
        {
            if (x1 > 1)
                updateLeft(left[0], left[1], max(1ll, x1 - t), x1 - 1, cost - 4, -4);
            if (x2 < m)
                updateRight(right[0], right[1], x2 + 1, min(m, x2 + t), cost - 4, -4);
        }
    }
    ll res = sum;
    for (int i = 1; i < m + 5; i++)
        right[1][i] += right[1][i - 1];
    for (int i = 1; i < m + 5; i++)
        right[0][i] += right[0][i - 1] + right[1][i - 1];
    for (int i = m - 3; i >= 0; i--)
        left[1][i] += left[1][i + 1];
    for (int i = m - 3; i >= 0; i--)
        left[0][i] += left[0][i + 1] + left[1][i + 1];
    for (int i = 0; i < m; i++)
        res = min(res, sum - left[0][i] - right[0][i]);
    cout << res << "\n";
}