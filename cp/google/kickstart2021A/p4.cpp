#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const ll inf = 1e12;

ll dfs(vector<vector<ll>> &A, vector<vector<ll>> &B, int cell, int r, int c)
{
    if (cell == r * c)
        return 1ll;
    int i = cell / c, j = cell % c;
    ll res = dfs(A, B, cell + 1, r, c);
    if (A[i][j] == -1)
    {
        A[i][j] = 1;
        res = min(res, B[i][j] + dfs(A, B, cell + 1, r, c));
        A[i][j] = -1;
    }
    return res;
}
ll solve()
{
    int r, c;
    int res = 0;
    cin >> r >> c;
    vector<vector<ll>> A(r, vector<ll>(c)), B(r, vector<ll>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> B[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}