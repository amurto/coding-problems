// https://codeforces.com/contest/1098/problem/B
// Nice table

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void rotate(vector<vector<char>> &grid, int &n, int &m)
{
    vector<vector<char>> mat(m, vector<char>(n));
    for (int j = 0, a = 0; j < m; j++, a++)
        for (int i = n - 1, b = 0; i >= 0; i--, b++)
            mat[a][b] = grid[i][j];
    grid = mat;
    swap(n, m);
}

int match(vector<char> &g, vector<char> &s)
{
    int cnt = 0;
    for (int i = 0; i < g.size(); i++)
        cnt += (g[i] != s[i]);
    return cnt;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m)), res(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    string chs = "ACGT";
    int mn = n * m + 1, r = 0;
    for (int is_rotate = 0; is_rotate < 2; is_rotate++)
    {
        for (int a = 1; a <= 3; a++)
        {
            swap(chs[1], chs[a]);
            vector<string> s(2);
            s[0] = chs.substr(0, 2);
            s[1] = chs.substr(2, 2);
            for (int t = 0; t < 2; t++)
            {
                vector<vector<char>> tmp = grid;
                int op = 0;
                for (int i = 0; i < n; i++)
                {
                    string ss = s[i % 2];
                    vector<char> c1(m), c2(m);
                    for (int id = 0; id < m; id++)
                        c1[id] = ss[id % 2];
                    swap(ss[0], ss[1]);
                    for (int id = 0; id < m; id++)
                        c2[id] = ss[id % 2];
                    int cnt1 = match(grid[i], c1);
                    int cnt2 = match(grid[i], c2);
                    if (cnt1 <= cnt2)
                        tmp[i] = c1;
                    else
                        tmp[i] = c2;
                    op += min(cnt1, cnt2);
                }
                if (op < mn)
                {
                    mn = op;
                    res = tmp;
                    r = is_rotate;
                }
                swap(s[0], s[1]);
            }
        }
        rotate(grid, n, m);
    }
    if (r)
    {
        rotate(grid, n, m);
        rotate(res, n, m);
        rotate(res, n, m);
        rotate(res, n, m);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << res[i][j];
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