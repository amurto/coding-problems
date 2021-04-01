// https://codeforces.com/contest/558/problem/E
// A Simple Task

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct node
{
    vector<int> arr;
    int k = 0;
    node()
    {
        arr.resize(26);
    }
    void merge(const node &l, const node &r)
    {
        for (int i = 0; i < 26; i++)
            arr[i] = l.arr[i] + r.arr[i];
    }
};

struct update
{
    vector<int> arr;
    int k = 0;
    update()
    {
        arr.resize(26);
    }
    update(vector<int> tmp, int kk)
    {
        arr.resize(26);
        arr = tmp;
        k = kk;
    }
    void purge(const int32_t &frnt, const int32_t &bck)
    {
        vector<int> tp = {frnt, bck};
        if (k == 0)
            swap(tp[0], tp[1]);
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; tp[j] > 0 && i < 26; i++)
            {
                if (arr[i] < tp[j])
                {
                    tp[j] -= arr[i];
                    arr[i] = 0;
                }
                else
                {
                    arr[i] -= tp[j];
                    tp[j] = 0;
                }
            }
            reverse(arr.begin(), arr.end());
        }
    }
    // combine the current update with the other update
    void combine(update &other, const int32_t &tl, const int32_t &tr)
    {
        k = other.k;
        arr = other.arr;
    }
    // store the correct information in the node x
    void apply(node &x, const int32_t &tl, const int32_t &tr)
    {
        x.k = k;
        x.arr = arr;
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
        update u1 = u[v], u2 = u[v];
        u1.purge(0, tr - tm);
        u2.purge(tm + 1 - tl, 0);
        apply(v << 1, tl, tm, u1);
        apply(v << 1 | 1, tm + 1, tr, u2);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }

    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd)
    {
        if (tl != tr)
        {
            lazy[v] = 1;
            u[v].combine(upd, tl, tr);
        }
        upd.apply(t[v], tl, tr);
    }

    template <typename T>
    void build(const T &str, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v].arr[str[tl]]++;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(str, v << 1, tl, tm);
        build(str, v << 1 | 1, tm + 1, tr);
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
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, update upd)
    {
        if (l > tr || r < tl)
            return;
        if (tl >= l && tr <= r)
        {
            upd.purge(tl - l, r - tr);
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
    void build(const T &str)
    {
        build(str, 1, 0, len - 1);
    }
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, update upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, l, r, k;
    cin >> n >> q;
    string str;
    cin >> str;
    vector<int> tmp(n);
    for (int i = 0; i < n; i++)
        tmp[i] = str[i] - 'a';
    segtree<node, update> s(n);
    s.build(tmp);
    while (q-- > 0)
    {
        cin >> l >> r >> k;
        s.rupd(l-1, r-1, update(s.query(l-1, r-1).arr, k));
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> ch = s.query(i, i).arr;
        for (int j = 0; j < 26; j++)
            if (ch[j])
                cout << char('a' + j);
    }
    return 0;
}