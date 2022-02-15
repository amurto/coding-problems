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
    ll sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
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
    int n, q;
    cin >> n >> q;
    vector<int> col(n, 1);
    set<pii> st;
    st.insert({0, n - 1});
    vector<ll> ops(n + 1);
    vector<pii> del, ins;
    FenwickTreeRP ft(n);

    auto query = [&](int id) -> ll
    {
        ll val = ft.point_query(id);
        pii cur = {id + 1, id + 1};
        auto it = st.lower_bound(cur);
        it--;
        val += ops[col[it->first]];
        return val;
    };
    
    for (int i = 0; i < q; i++)
    {
        string str;
        cin >> str;
        if (str == "Color")
        {
            int l, r, c;
            cin >> l >> r >> c;
            l--;
            r--;
            pii cur = {l + 1, l + 1};
            auto it = st.lower_bound(cur);
            it--;

            while (it != st.end() && it->first <= r)
            {
                int c_l = it->first, c_r = it->second, cur_col = col[it->first];
                if (it->first < l && it->second > r)
                {
                    ins.pb({it->first, l - 1});
                    ins.pb({r + 1, it->second});
                    col[r + 1] = col[it->first];
                    c_l = l;
                    c_r = r;
                }
                else if (it->first < l)
                {
                    ins.pb({it->first, l - 1});
                    c_l = l;
                }
                else if (it->second > r)
                {
                    ins.pb({r + 1, it->second});
                    col[r + 1] = col[it->first];
                    c_r = r;
                }
                ft.range_update(c_l, c_r, ops[cur_col]);
                del.pb(*it);
                it++;
            }
            for (pii dl : del)
                st.erase(dl);
            ins.pb({l, r});
            for (pii is : ins)
                st.insert(is);
            ins.clear();
            del.clear();
            col[l] = c;
            ft.range_update(l, r, -ops[c]);
        }
        else if (str == "Add")
        {
            int c;
            ll x;
            cin >> c >> x;
            ops[c] += x;
        }
        else
        {
            int id;
            cin >> id;
            id--;
            ll res = query(id);
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