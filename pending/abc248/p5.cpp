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

bool eq(ll y1, ll x1, ll y2, ll x2)
{
    return y1 == y2 && x1 == x2;
}

void solve()
{
    int n, k, res = 0;
    cin >> n >> k;
    vector<ll> X(n), Y(n);
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];
    if (k == 1)
    {
        cout << "Infinity\n";
        return;
    }
    vector<vector<ll>> dpY(n, vector<ll>(n)), dpX(n, vector<ll>(n));
    vector<vector<bool>> vis(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            dpY[i][j] = Y[j] - Y[i];
            dpX[i][j] = X[j] - X[i];
            if (dpY[i][j] == 0)
            {
                if (dpX[i][j] < 0)
                    dpX[i][j] *= -1;
            }
            else if (dpY[i][j] < 0)
            {
                dpY[i][j] *= -1;
                dpX[i][j] *= -1;
            }
            ll g = __gcd(abs(dpY[i][j]), abs(dpX[i][j]));
            dpY[i][j] /= g;
            dpX[i][j] /= g;
            dpY[j][i] = dpY[i][j];
            dpX[j][i] = dpX[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!vis[i][j])
            {
                vector<int> ids;
                ids.pb(i);
                ll y = dpY[i][j], x = dpX[i][j];
                for (int t = 0; t < n; t++)
                    if (t != i && eq(y, x, dpY[i][t], dpX[i][t]))
                        ids.pb(t);
                int sz = (int)ids.size();
                if (sz >= k)
                    res++;
                for (int i1 = 0; i1 < sz; i1++)
                    for (int i2 = i1 + 1; i2 < sz; i2++)
                        vis[ids[i1]][ids[i2]] = vis[ids[i2]][ids[i1]] = true;
            }
        }
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}