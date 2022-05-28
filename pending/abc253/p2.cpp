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

int solve()
{
    int h, w, si = -1, sj = -1, ti = -1, tj = -1;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++)
        cin >> grid[i];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == 'o')
            {
                if (si >= 0)
                    ti = i, tj = j;
                else
                    si = i, sj = j;
            }
        }
    }
    return abs(si - ti) + abs(sj - tj);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}