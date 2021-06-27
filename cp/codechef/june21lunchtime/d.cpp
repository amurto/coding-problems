#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N = 50;
int grid[55][55];

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
    cout << "?" << endl;
    for (int i = 0; i < N; i++)
    {
        string str = "";
        for (int j = 0; j < N; j++)
            str.pb(char(grid[i][j] + '0'));
        cout << str << endl;
    }
    fflush(stdout);
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

void solve()
{
    cin >> N;
    int low = 0, high = N - 2;
    while (low < high)
    {
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

    // column found
    // find minimum cells to be colored in column c such that grid is valid
    low = 0, high = N - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        clearGrid();
        for (int j = 0; j <= c; j++)
            grid[0][j] = 1;
        for (int i = 0; i <= mid; i++)
            grid[i][c] = 1;
        for (int j = c; j < N; j++)
            grid[mid][j] = 1;
        for (int i = mid; i < N; i++)
            grid[i][N - 1] = 1;
        int ans = query();
        if (ans == 1)
            high = mid;
        else
            low = mid + 1;
    }
    int r = low;
    if (c == N - 2)
        r++;
    // row found
    cout << "!" << endl;
    cout << r << " " << c << endl;
    int res;
    cin >> res;
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