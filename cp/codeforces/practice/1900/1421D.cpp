// https://codeforces.com/contest/1421/problem/D
// Hexagons

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll di[6] = {1, 0, -1, -1, 0, 1}, dj[6] = {1, 1, 0, -1, -1, 0};

int sn(ll v)
{
    if (v < 0)
        return -1;
    return v == 0 ? 0 : 1;
}

ll solve()
{
    ll x, y, res = LLONG_MAX;
    cin >> x >> y;
    vector<ll> c(6);
    for (int i = 0; i < 6; i++)
        cin >> c[i];
    if (x == 0 && y == 0)
        return 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (di[i] != 0 && x != 0 && sn(x) == sn(di[i]))
                {
                    ll px = abs(x) * di[i], py = abs(x) * dj[i];
                    ll yt = y - py;
                    if (sn(dj[j]) == sn(yt))
                    {
                        px += abs(yt) * di[j];
                        py += abs(yt) * dj[j];
                        if (px == x && py == y)
                            res = min(res, abs(x) * c[i] + abs(yt) * c[j]);
                    }
                }
                if (dj[i] != 0 && y != 0 && sn(y) == sn(dj[i]))
                {
                    ll px = abs(y) * di[i], py = abs(y) * dj[i];
                    ll xt = x - px;
                    if (sn(di[j]) == sn(xt))
                    {
                        px += abs(xt) * di[j];
                        py += abs(xt) * dj[j];
                        if (px == x && py == y)
                            res = min(res, abs(y) * c[i] + abs(xt) * c[j]);
                    }
                }
                swap(i, j);
            }
        }
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