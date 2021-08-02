#ifdef amurto
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

// Area = b/2 + i - 1
// b -> boundary
// i -> integer
// 2*Area = b + 2i - 2
// 2i = 2*Area - b + 2
bool picks(int b)
{
    return b % 4 == 0;
}

int dis(pii p1, pii p2)
{
    return __gcd(abs(p2.first - p1.first), abs(p2.second - p1.second));
}

ll ncr(int n, int r)
{
    if (r == 0)
        return 1;
    if (r > n || n < 0 || r < 0)
        return 0;
    if (r == 2)
        return (n * 1ll * (n - 1)) / 2;
    if (r == 3)
        return (n * 1ll * (n - 1) * (n - 2)) / 6;
    return n;
}

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<pii> pts(n);
    vector<vector<int>> cnt(3, vector<int>(3)), cur(3, vector<int>(3));
    vector<int> sx = {0, 0, 2, 2}, sy = {0, 2, 0, 2};
    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].first >> pts[i].second;
        cnt[pts[i].first % 4][pts[i].second % 4]++;
    }
    for (int i = 0; i < 4; i++)
    {
        pii p1 = {sx[i], sy[i]};
        cur[p1.first][p1.second]++;
        for (int j = 0; j <= i; j++)
        {
            pii p2 = {sx[j], sy[j]};
            cur[p2.first][p2.second]++;
            for (int k = 0; k <= j; k++)
            {
                pii p3 = {sx[k], sy[k]};
                cur[p3.first][p3.second]++;
                if (picks(dis(p1, p2) + dis(p2, p3) + dis(p3, p1)))
                {
                    ll x = 1;
                    for (int t = 0; t < 4; t++)
                        x *= ncr(cnt[sx[t]][sy[t]], cur[sx[t]][sy[t]]);
                    res += x;
                }
                cur[p3.first][p3.second]--;
            }
            cur[p2.first][p2.second]--;
        }
        cur[p1.first][p1.second]--;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}