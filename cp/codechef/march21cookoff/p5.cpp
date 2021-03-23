#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
string mm = "URDL";
map<int, int> mp;

class pipe
{
public:
    int k, r, c;
    pipe() {}
    pipe(int k, int r, int c) : k(k), r(r), c(c) {}
    bool operator<(const pipe &j) const
    {
        return k > j.k;
    }
};

bool check(vector<vector<int>> &grid, vector<string> &edge, int n, int m, int k, int t)
{
    vector<vector<int>> dis(n, vector<int>(m, 1e9 + 5));
    priority_queue<pipe> pq;
    pq.push(pipe(0, 0, 0));
    while (!pq.empty())
    {
        pipe pp = pq.top();
        pq.pop();
        if (pp.k > dis[pp.r][pp.c])
            continue;
        for (int dir = mp[edge[pp.r][pp.c]], cnt = 0; cnt < 4; cnt++, dir++)
        {
            dir %= 4;
            int i = pp.r + di[dir], j = pp.c + dj[dir];
            if (i >= 0 && i < n && j >= 0 && j < m && grid[pp.r][pp.c] - cnt >= t && pp.k + cnt < dis[i][j])
            {
                dis[i][j] = pp.k + cnt;
                pq.push(pipe(pp.k + cnt, i, j));
            }
        }
    }
    return dis[n - 1][m - 1] <= k;
}

int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<string> edge(n);
    for (int i = 0; i < n; i++)
        cin >> edge[i];
    if (n == 1 && m == 1)
        return 0;
    int l = 0, r = 1e9 + 5, res = 0;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (check(grid, edge, n, m, k, mid))
        {
            res = max(res, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if (check(grid, edge, n, m, k, l))
        res = max(res, l);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 4; i++)
        mp[mm[i]] = i;
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}