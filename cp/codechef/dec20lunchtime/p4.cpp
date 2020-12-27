#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool check(vector<vector<int>> &A, int n, int m, int r, int c)
{
    bool good = true;
    int ele = A[r][c];
    for (int i = r + 1, j = c + 1; i < n && j < m; i++, j++)
    {
        if (A[i][j] != ele)
        {
            good = false;
            break;
        }
    }
    return good;
}

void solve()
{
    int n, m, q, f = 0;
    unordered_set<int> row, col;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    for (int i = 1; i < n; i++)
        if (check(A, n, m, i, 0))
            row.insert(i);
    for (int i = 1; i < m; i++)
        if (check(A, n, m, 0, i))
            col.insert(i);
    if (check(A, n, m, 0, 0))
        f = 1;
    cin >> q;
    while (q-- > 0)
    {
        int r, c, e;
        cin >> r >> c >> e;
        r--;
        c--;
        A[r][c] = e;
        int mn = min(r, c);
        r -= mn;
        c -= mn;
        bool good = check(A, n, m, r, c);
        if (r > c)
        {
            if (good)
                row.insert(r);
            else
                row.erase(r);
        }
        else if (r < c)
        {
            if (good)
                col.insert(c);
            else
                col.erase(c);
        }
        else
        {
            if (good)
                f = 1;
            else
                f = 0;
        }
        if ((row.size() + col.size() + f) == (m + n - 1))
            cout << "Yes\n";
        else
            cout << "No\n";
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