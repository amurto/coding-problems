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

void solve()
{
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    ll h = q - p + 1, w = s - r + 1;
    vector<vector<char>> grid(h, vector<char>(w, '.'));
    for (ll i = 0, x = p; i < h; i++, x++)
    {
        for (ll j = 0, y = r; j < w; j++, y++)
        {
            ll da = x - a, db = y - b;
            if (abs(da) == abs(db))
                grid[i][j] = '#';
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cout << grid[i][j];
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}