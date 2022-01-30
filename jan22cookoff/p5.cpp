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

const ll inf = 1e17;
ll solve()
{
    int n, k;
    cin >> n >> k;
    int h = k / 2;
    ll res = 0;
    vector<ll> X(n), S(n);
    for (int i = 0; i < n; i++)
        cin >> X[i] >> S[i];
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i1, int i2)
         { return X[i1] < X[i2]; });

    if (k == 2)
    {
        ll pre = S[ids[0]];
        for (int i = 1; i < n; i++)
        {
            pre += abs(X[ids[i]] - X[ids[i - 1]]);
            res = max(res, pre + S[ids[i]]);
            pre = max(pre, S[ids[i]]);
        }
        return res;
    }
    vector<ll> pre(n, -inf), suf(n, -inf);

    auto cmp = [&](int i1, int i2)
    {
        ll c1 = (max(X[i1], X[i2]) - X[i1]) * 2 + S[i1], c2 = (max(X[i1], X[i2]) - X[i2]) * 2 + S[i2];
        return c1 > c2;
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq1(cmp);

    ll sum1 = 0;
    for (int i = 0; i < h - 1; i++)
    {
        ll last = X[ids[i]];
        if (i - 1 >= 0)
            last = X[ids[i - 1]];
        sum1 += ((X[ids[i]] - last) * 2 * i);
        pq1.push(ids[i]);
        sum1 += S[ids[i]];
    }
    int pt = -1;
    for (int i = h - 1; i < n; i++)
    {
        ll last = X[ids[i]];
        if (i - 1 >= 0)
            last = X[ids[i - 1]];
        sum1 += ((X[ids[i]] - last) * (h - 1) * 2);
        if (pt == -1)
            pt = i;
        else
        {
            if (S[ids[i]] >= X[ids[i]] - X[pt] + S[pt])
            {
                int idx = pq1.top();
                if (cmp(pt, idx))
                {
                    pq1.pop();
                    sum1 -= ((X[ids[i]] - X[idx]) * 2 + S[idx]);
                    pq1.push(pt);
                    sum1 += ((X[ids[i]] - X[pt]) * 2 + S[pt]);
                }
                pt = ids[i];
            }
        }
        pre[i] = sum1 + X[ids[i]] - X[pt] + S[pt];
    }

    priority_queue<int, vector<int>, decltype(cmp)> pq2(cmp);

    ll sum2 = 0;
    for (int i = n - 1; i > n - h; i--)
    {
        ll last = X[ids[i]];
        if (i + 1 < n)
            last = X[ids[i + 1]];
        sum2 += ((last - X[ids[i]]) * 2 * i);
        pq2.push(ids[i]);
        sum2 += S[ids[i]];
    }
    pt = -1;
    for (int i = n - h; i >= 0; i--)
    {
        ll last = X[ids[i]];
        if (i + 1 < n)
            last = X[ids[i + 1]];
        sum2 += ((last - X[ids[i]]) * (h - 1) * 2);
        if (pt == -1)
            pt = i;
        else
        {
            if (S[ids[i]] >= abs(X[ids[i]] - X[pt]) + S[pt])
            {
                int idx = pq2.top();
                if (cmp(pt, idx))
                {
                    pq2.pop();
                    sum2 -= (abs(X[ids[i]] - X[idx]) * 2 + S[idx]);
                    pq2.push(pt);
                    sum2 += (abs(X[ids[i]] - X[pt]) * 2 + S[pt]);
                }
                pt = ids[i];
            }
        }
        suf[i] = sum2 + abs(X[ids[i]] - X[pt]) + S[pt];
    }
    for (int i = 1; i < n; i++)
    {
        ll dis = X[ids[i]] - X[ids[i - 1]];
        res = max(res, pre[i - 1] + 1ll * h * dis * 2 - dis + suf[i]);
    }
    return res;
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