// https://codeforces.com/contest/912/problem/D
// Fishes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

double solve()
{
    int n, m, r, k;
    cin >> n >> m >> r >> k;
    double den = 1.0 * (n - r + 1) * 1ll * (m - r + 1), res = 0;
    vector<int> rows(r + 1), cols(r + 1);
    for (int i = 1; i <= n; i++)
        rows[min({i, n - i + 1, r, n - r + 1})]++;
    for (int j = 1; j <= m; j++)
        cols[min({j, m - j + 1, r, m - r + 1})]++;
    int mx = 0;
    for (int i = 1; i <= r; i++)
        if (cols[i] > 0)
            mx = i;
    auto cmp = [&](pii &p1, pii &p2)
    {
        return p1.first * 1ll * p1.second < p2.first * 1ll * p2.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    for (int i = 1; i <= r; i++)
        if (rows[i] > 0)
            pq.push({i, mx});
    while (k > 0)
    {
        pii cur = pq.top();
        pq.pop();
        ll cnt = rows[cur.first] * 1ll * cols[cur.second];
        ll req = min(1ll * k, cnt);
        res += (1.0 * cur.first * 1ll * cur.second) / den * req;
        cnt -= req;
        k -= req;
        if (cnt == 0 && cur.second > 1)
            pq.push({cur.first, cur.second - 1});
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cout << solve() << "\n";
    return 0;
}