#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back

// Range AP Updates
struct node
{
    int v = 0; // identity
    node() {}
    node(int val)
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
    int a = 0, d = 0, l = 0;
    update() {}
    update(int first_term, int diff, int first_idx)
    {
        a = first_term;
        d = diff;
        l = first_idx;
    }

    void fix(const int32_t &tl, const int32_t &tr)
    {
        a += (tl - l) * d;
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
        x.v += ((tr - tl + 1) * (2 * a + (tr - tl) * d)) / 2;
    }

    // put at first line in apply function of segtree
    // upd.fix(tl, tr);
};
