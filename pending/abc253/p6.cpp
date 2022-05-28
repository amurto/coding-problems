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

// doesn't support range update and range query
// supports range update and point query
struct FenwickTreeRP
{
    vector<ll> bit; // binary indexed tree
    int n;
    FenwickTreeRP(int sz)
    {
        this->n = sz + 1;
        bit.assign(n + 1, 0);
    }
    FenwickTreeRP(vector<ll> a)
        : FenwickTreeRP(a.size())
    {
        // creates same BIT from array using differences
        vector<ll> diff = a;
        for (int i = 1; i < (int)a.size(); i++)
            diff[i] = a[i] - a[i - 1];
        for (size_t i = 0; i < diff.size(); i++)
            update(i, diff[i]);
    }
    ll sum(int idx)
    {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    // int sum(int l, int r)
    // {
    //     return sum(r) - sum(l - 1);
    // }
    void update(int idx, ll delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    void range_update(int l, int r, ll val)
    {
        update(l, val);
        update(r + 1, -val);
    }
    // use this
    ll point_query(int idx)
    {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    void display()
    {
        for (int i = 0; i < n - 1; i++)
            cout << point_query(i) << " ";
        cout << "\n";
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> t(q), l(q), r(q), x(q), last(n);
    vector<vector<int>> rows(n), rows_upd(n);
    map<pii, ll> pre;
    FenwickTreeRP ft(m);
    for (int i = 0; i < q; i++)
    {
        cin >> t[i];
        if (t[i] == 1)
        {
            cin >> l[i] >> r[i] >> x[i];
            l[i]--;
            r[i]--;
        }
        else if (t[i] == 2)
        {
            cin >> l[i] >> x[i];
            l[i]--;
            rows_upd[l[i]].pb(i);
        }
        else
        {
            cin >> l[i] >> r[i];
            l[i]--;
            r[i]--;
            rows[l[i]].pb(i);
        }
    }
    for (int i = 0; i < q; i++)
    {
        if (t[i] == 1)
        {
            ft.range_update(l[i], r[i], x[i]);
        }
        else if (t[i] == 2)
        {
            last[l[i]] = x[i];
            if (!rows[l[i]].empty())
            {
                int sz = (int)rows[l[i]].size();
                int nxt = lower_bound(rows_upd[l[i]].begin(), rows_upd[l[i]].end(), i) - rows_upd[l[i]].begin();
                if (nxt + 1 >= (int)rows_upd[l[i]].size())
                    nxt = q;
                else
                    nxt = rows_upd[l[i]][nxt + 1];
                int id = lower_bound(rows[l[i]].begin(), rows[l[i]].end(), i) - rows[l[i]].begin();
                while (id < sz && rows[l[i]][id] < nxt)
                {
                    pre[{l[i], r[rows[l[i]][id]]}] = ft.point_query(r[rows[l[i]][id]]);
                    id++;
                }
            }
        }
        else
        {
            ll res = ft.point_query(r[i]) - pre[{l[i], r[i]}] + last[l[i]];
            cout << res << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}