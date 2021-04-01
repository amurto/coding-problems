// https://codeforces.com/contest/610/problem/D
// Vika and Segments

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, pair<int, int>> ppi;
#define pb push_back

int mergeIntervals(vector<pii> &intervals)
{
    sort(intervals.begin(), intervals.end());
    deque<pii> dq;
    vector<pii> ans;
    for (pii it : intervals)
    {
        int beg = it.first, end = it.second;
        while (!dq.empty() && it.first <= dq.back().second)
        {
            beg = min(beg, dq.back().first);
            end = max(end, dq.back().second);
            dq.pop_back();
        }
        dq.push_back({beg, end});
    }
    int res = 0;
    while (!dq.empty())
    {
        ans.pb(dq.back());
        res += ans.back().second - ans.back().first + 1;
        dq.pop_back();
    }
    intervals = ans;
    return res;
}

// Merge Sort Tree
struct mstree
{
    int len;
    vector<vector<vector<int>>> t;
    mstree(int l)
    {
        len = l;
        t.resize(4 * len);
    }

    vector<vector<int>> merge(int l, int r)
    {
        vector<vector<int>> iv(2);
        for (int x = 0; x < 2; x++)
        {
            int sz1 = t[l][x].size(), sz2 = t[r][x].size();
            vector<int> arr(sz1 + sz2);
            int i = 0, j = 0, idx = 0;
            while (i < sz1 && j < sz2)
            {
                arr[idx++] = (t[l][x][i] < t[r][x][j]) ? t[l][x][i++] : t[r][x][j++];
            }
            while (i < sz1)
            {
                arr[idx++] = t[l][x][i++];
            }
            while (j < sz2)
            {
                arr[idx++] = t[r][x][j++];
            }
            iv[x] = arr;
        }
        return iv;
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v].resize(2);
            for (pii p : arr[tl])
            {
                t[v][0].pb(p.first);
                t[v][1].pb(p.second);
            }
            sort(t[v][0].begin(), t[v][0].end());
            sort(t[v][1].begin(), t[v][1].end());
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v] = merge(v << 1, v << 1 | 1);
    }

    // number of intervals that contain x
    int query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, int x)
    {
        if (l > tr || r < tl)
            return 0;
        if (tl >= l && tr <= r)
        {
            int cnt = t[v][0].size();
            cnt -= t[v][0].size() - (upper_bound(t[v][0].begin(), t[v][0].end(), x) - t[v][0].begin());
            cnt -= (lower_bound(t[v][1].begin(), t[v][1].end(), x) - t[v][1].begin());
            return cnt;
        }
        int32_t tm = (tl + tr) >> 1;
        return query(v << 1, tl, tm, l, r, x) + query(v << 1 | 1, tm + 1, tr, l, r, x);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    int query(const int32_t &l, const int32_t &r, int x)
    {
        return query(1, 0, len - 1, l, r, x);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x1, y1, x2, y2;
    cin >> n;
    vector<ppi> arr(n);
    vector<int> X, Y;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        arr[i].first.first = x1;
        arr[i].first.second = y1;
        arr[i].second.first = x2;
        arr[i].second.second = y2;
        if (x1 == x2)
            X.pb(x1);
        else
            Y.pb(y2);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int xsz = X.size(), ysz = Y.size();
    map<int, int> mpx, mpy;
    for (int i = 0; i < xsz; i++)
        mpx[X[i]] = i;
    for (int i = 0; i < ysz; i++)
        mpy[Y[i]] = i;
    vector<vector<pii>> Xst(xsz), Yst(ysz);
    for (ppi p : arr)
    {
        if (p.first.first == p.second.first)
            Xst[mpx[p.first.first]].pb({p.first.second, p.second.second});
        else
            Yst[mpy[p.first.second]].pb({p.first.first, p.second.first});
    }
    ll res = 0;
    for (int i = 0; i < xsz; i++)
        res += 1ll * mergeIntervals(Xst[i]);
    for (int i = 0; i < ysz; i++)
        res += 1ll * mergeIntervals(Yst[i]);
    if (ysz > 0)
    {
        mstree ms(ysz);
        ms.build(Yst);
        for (int i = 0; i < xsz; i++)
        {
            for (pii p : Xst[i])
            {
                int ldx = lower_bound(Y.begin(), Y.end(), p.first) - Y.begin();
                int rdx = upper_bound(Y.begin(), Y.end(), p.second) - Y.begin();
                rdx--;
                if (ldx <= rdx)
                    res -= ms.query(ldx, rdx, X[i]);
            }
        }
    }
    cout << res << "\n";
    return 0;
}