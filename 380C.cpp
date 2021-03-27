// https://codeforces.com/contest/380/problem/C
// Sereja and Brackets

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct node
{
    int seq = 0, op = 0, cl = 0;
    node() {}
    void merge(const node &l, const node &r)
    {
        seq += l.seq + r.seq;
        op += r.op;
        cl += l.cl;
        if (l.op > r.cl)
            op += l.op - r.cl;
        else
            cl += r.cl - l.op;
        seq += 2 * min(l.op, r.cl);
    }
};

template <typename node>
struct segtree
{
    int len;
    vector<node> t;
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
    }

    void build(string &str, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            if (str[tl] == '(')
                t[v].op++;
            else
                t[v].cl++;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(str, v << 1, tl, tm);
        build(str, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
        cout << "v: " << v << "\n";
    }

    node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
            return node();
        if (tl >= l && tr <= r)
        {
            // cout << v << "\n";
            return t[v];
        }
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

public:
    void build(string &str)
    {
        build(str, 1, 0, len - 1);
    }
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, l, r;
    string str;
    cin >> str >> m;
    int n = str.length();
    segtree<node> s(n);
    s.build(str);
    while (m-- > 0)
    {
        cin >> l >> r;
        l--;
        r--;
        cout << s.query(l, r).cl << "\n";
    }
    return 0;
}