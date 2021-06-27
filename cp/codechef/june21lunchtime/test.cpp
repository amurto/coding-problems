#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

// for 64 bit, use mt19937_64
mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
// Just call rand(minValue, maxValue);
// Note: it doesn't guarantee distinct values.
int rand(int l, int r)
{
    static mt19937
        rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> ludo(l, r);
    return ludo(rng);
}

const int N = 4;
int grid[N][N];

int ti = rand(1, N - 2), tj = rand(1, N - 2), q = 0;

int di[2] = {0, 1}, dj[2] = {1, 0};
bool bfs(pii src, pii des)
{
    vector<vector<bool>> vis(N, vector<bool>(N));
    queue<pii> q;
    vis[src.first][src.second] = true;
    q.push(src);
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int dir = 0; dir < 2; dir++)
        {
            int i = cur.first + di[dir], j = cur.second + dj[dir];
            if (i == des.first && j == des.second)
                return true;
            if (i < N && j < N && !vis[i][j] && grid[i][j] == 1)
            {
                vis[i][j] = true;
                q.push({i, j});
            }
        }
    }
    return false;
}

void colorRow(int l, int r)
{
    for (int i = l; i <= r; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = 1;
}

void colorCol(int l, int r)
{
    for (int i = 0; i < N; i++)
        for (int j = l; j <= r; j++)
            grid[i][j] = 1;
}

void clearGrid()
{
    memset(grid, 0, sizeof(grid));
}

int query()
{
    q++;
    cout << "?" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j];
        cout << endl;
    }
    int ans;
    // cin >> ans;
    ans = bfs({0, 0}, {ti, tj}) && bfs({ti, tj}, {N - 1, N - 1});
    cout << ans << endl;
    if (ans == -1)
        exit(0);
    return ans;
}

void solve()
{
    ti = 2;
    tj = 2;
    q = 0;
    int low = 0, high = N - 2;
    while (low < high)
    {
        // cout << low << " " << high << "\n";
        int mid = low + (high - low + 1) / 2;
        clearGrid();
        colorRow(0, 0);
        colorCol(mid + 1, N - 1);
        int ans = query();
        if (ans == 1)
            low = mid;
        else
            high = mid - 1;
    }
    int c = low;
    cout << "Hi : " << c << endl;
    if (c == 0)
        c++;
    else if (c != N - 2)
    {
        // check if column is same as c
        // only possible if it is in (1,c)
        clearGrid();
        grid[0][0] = 1;
        colorRow(1, 1);
        colorCol(N - 1, N - 1);
        int v1 = query();
        clearGrid();
        grid[0][0] = 1;
        for (int j = 0; j <= c; j++)
            grid[1][j] = 1;
        for (int j = c; j < N; j++)
            grid[N - 1][j] = 1;
        colorCol(c, c);
        int v2 = query();
        if (v1 + v2 < 2)
            c++;
    }

    cout << tj << " " << c << endl;
    // // column found
    // // find minimum cells to be colored in column c such that grid is valid
    // low = 0, high = N - 1;
    // while (low < high)
    // {
    //     int mid = low + (high - low) / 2;
    //     clearGrid();
    //     for (int j = 0; j <= c; j++)
    //         grid[0][j] = 1;
    //     for (int i = 0; i <= mid; i++)
    //         grid[i][c] = 1;
    //     for (int j = c; j < N; j++)
    //         grid[mid][j] = 1;
    //     for (int i = mid; i < N; i++)
    //         grid[i][N - 1] = 1;
    //     int ans = query();
    //     if (ans == 1)
    //         high = mid;
    //     else
    //         low = mid + 1;
    // }
    // int r = low;
    // if (c == N - 2)
    //     r++;
    // cout << "q : " << q << endl;
    // cout << ti << " " << tj << endl;
    // cout << r << " " << c << endl;
    // row found
    // cout << "! " << r << " " << c << endl;
    // int f;
    // cin >> f;
    // if (f == 0)
    //     exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t-- > 0)
        solve();
    return 0;
}