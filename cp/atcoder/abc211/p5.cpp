#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
bool is_set(ll x, ll p)
{
    return ((x >> p) & 1);
}

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<vector<ll>> cell(n, vector<ll>(n));
    for (int i = 0, c = 0; i < n; i++)
        for (int j = 0; j < n; j++, c++)
            cell[i][j] = c;
    set<ll> st;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == '.')
                st.insert(1ll << cell[i][j]);
    for (int t = 2; t <= k; t++)
    {
        set<ll> tmp;
        for (ll x : st)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (is_set(x, cell[i][j]))
                    {
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int ni = i + di[dir], nj = j + dj[dir];
                            if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] != '#' && !is_set(x, cell[ni][nj]))
                                tmp.insert(x | (1ll << cell[ni][nj]));
                        }
                    }
                }
            }
        }
        st = tmp;
    }
    return (int)st.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}