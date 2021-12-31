#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e18;

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
            add(i, diff[i]);
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
    void add(int idx, int delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    void range_add(int l, int r, int val)
    {
        add(l, val);
        add(r + 1, -val);
    }
    int point_query(int idx)
    {
        int ret = 0;
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

ll solve()
{
    int n;
    ll dis = 0, res = inf;
    string s, t;
    cin >> n >> s >> t;
    vector<vector<int>> ids(26);
    vector<int> ptr(26);
    for (int i = 0; i < n; i++)
        ids[s[i] - 'a'].pb(i);
    for (int i = 0; i < 26; i++)
        ids[i].pb(n);
    vector<ll> arr(n);
    iota(arr.begin(), arr.end(), 0ll);
    FenwickTreeRP ft = FenwickTreeRP(arr);
    for (int i = 0; i < n; i++)
    {
        int ch = t[i] - 'a';
        for (int c = 0; c < ch; c++)
            if (ids[c][ptr[c]] < n)
                res = min(res, dis + ft.point_query(ids[c][ptr[c]]) - i);
        if (ids[ch][ptr[ch]] >= n)
            return res >= inf ? -1 : res;
        dis += ft.point_query(ids[ch][ptr[ch]]) - i;
        ft.range_add(0, ids[ch][ptr[ch]], 1);
        ptr[ch]++;
    }
    return res >= inf ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}