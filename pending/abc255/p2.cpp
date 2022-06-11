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

bool contains(double x1, double y1, double x2, double y2, double r)
{
    double dx = x1 - x2, dy = y1 - y2;
    return dx * dx + dy * dy <= r * r;
}

double solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n), arr(k);
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    double low = 0, high = 1e9, res = 1e9;
    for (int t = 0; t < 60; t++)
    {
        double mid = low + (high - low) / 2.0;
        vector<bool> vis(n);
        for (int id : arr)
        {
            vis[id - 1] = true;
            for (int i = 0; i < n; i++)
                if (!vis[i] && contains(x[id - 1], y[id - 1], x[i], y[i], mid))
                    vis[i] = true;
        }
        bool pos = true;
        for (int i = 0; pos && i < n; i++)
            if (!vis[i])
                pos = false;
        if (pos)
        {
            res = min(res, mid);
            high = mid;
        }
        else
            low = mid;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(18);
    cout << solve() << "\n";
    return 0;
}