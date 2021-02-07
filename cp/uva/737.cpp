// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=678
// Gleaming the Cubes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve(int n)
{
    int X[n], Y[n], Z[n], S[n];
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i] >> Z[i] >> S[i];
    int cx = X[0], cy = Y[0], cz = Z[0], sx = X[0] + S[0], sy = Y[0] + S[0], sz = Z[0] + S[0];
    for (int i = 1; i < n; i++)
    {
        if (sx <= X[i] || X[i] + S[i] <= cx)
            return 0;
        cx = max(cx, X[i]);
        sx = min(sx, X[i] + S[i]);
        if (sy <= Y[i] || Y[i] + S[i] <= cy)
            return 0;
        cy = max(cy, Y[i]);
        sy = min(sy, Y[i] + S[i]);
        if (sz <= Z[i] || Z[i] + S[i] <= cz)
            return 0;
        cz = max(cz, Z[i]);
        sz = min(sz, Z[i] + S[i]);
    }
    return (sx - cx) * (sy - cy) * (sz - cz);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n && n > 0)
        cout << solve(n) << "\n";
    return 0;
}