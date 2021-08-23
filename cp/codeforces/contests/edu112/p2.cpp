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

void solve()
{
    int W, H, x1, y1, x2, y2, w, h, mn = 1e9;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    pii down = {W, y1 - 0}, up = {W, H - y2}, lt = {x1, H}, rt = {W - x2, H};

    // down
    if (down.second + up.second >= h)
        mn = min(mn, max(0, h - down.second));
    // up
    if (down.second + up.second >= h)
        mn = min(mn, max(0, h - up.second));
    // left
    if (lt.first + rt.first >= w)
        mn = min(mn, max(0, w - lt.first));
    // right
    if (lt.first + rt.first >= w)
        mn = min(mn, max(0, w - rt.first));
    if (mn == 1e9)
    {
        cout << "-1\n";
        return;
    }
    cout << (1.0 * mn) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}