// https://codeforces.com/contest/1181/problem/D
// Irrigation

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

struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;
    FenwickTree(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    FenwickTree(vector<int> a)
        : FenwickTree(a.size())
    {
        // creates same BIT from array using differences
        vector<int> diff = a;
        for (int i = 2; i < a.size(); i++)
            diff[i] = a[i] - a[i - 1];
        for (size_t i = 0; i < diff.size(); i++)
            add(i, diff[i]);
    }
    int sum(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    void add(int idx, int delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> arr(n), ids(q), deg(m + 1), res(q);
    vector<ll> qs(q);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        deg[arr[i]]++;
    }
    for (int i = 0; i < q; i++)
        cin >> qs[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return qs[i1] < qs[i2]; });
    FenwickTree ft(m + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= m; i++)
        pq.push({deg[i], i});
    int id = 0, mn = pq.top().first;
    ll cur = n, op = n, cnt = 0;
    while (!pq.empty())
    {
        while (!pq.empty() && pq.top().first == mn)
        {
            pii tp = pq.top();
            ft.add(tp.second, 1);
            cnt++;
            pq.pop();
        }
        ll r = cur + cnt;
        while (id < q && qs[ids[id]] <= r)
        {
            int req = qs[ids[id]] - cur, low = 1, high = m;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if (ft.sum(mid) >= req)
                    high = mid;
                else
                    low = mid + 1;
            }
            res[ids[id]] = low;
            id++;
        }
        cur = r;
        mn++;
    }
    while (id < q)
    {
        res[ids[id]] = (qs[ids[id]] - cur) % m;
        if (res[ids[id]] == 0)
            res[ids[id]] = m;
        id++;
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}