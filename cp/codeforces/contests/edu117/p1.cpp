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

int distance(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

void solve()
{
    int x, y;
    cin >> x >> y;
    if ((x + y) & 1)
        cout << "-1 -1\n";
    else
    {
        int px = x, py = y, dis = (x + y) / 2;
        if (x > y)
            px -= dis;
        else
            py -= dis;
        cout << px << " " << py << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}