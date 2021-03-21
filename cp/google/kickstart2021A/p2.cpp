#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void display(vector<vector<int>> &grid, int r, int c)
{
    cout << "\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

ll solve()
{
    int r, c, d = 0;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c)), U(r, vector<int>(c)), D(r, vector<int>(c)), L(r, vector<int>(c)), R(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            U[i][j] = D[i][j] = L[i][j] = R[i][j] = grid[i][j];
    for (int i = 0; i < r; i++)
    {
        for (int j = 1; j < c; j++)
            if (L[i][j] > 0)
                L[i][j] += L[i][j - 1];
        for (int j = c - 2; j >= 0; j--)
            if (R[i][j] > 0)
                R[i][j] += R[i][j + 1];
    }
    for (int j = 0; j < c; j++)
    {
        for (int i = 1; i < r; i++)
            if (U[i][j] > 0)
                U[i][j] += U[i - 1][j];
        for (int i = r - 2; i >= 0; i--)
            if (D[i][j] > 0)
                D[i][j] += D[i + 1][j];
    }
    // display(D, r, c);
    ll res = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // left up
            if (L[i][j] >= 4 && U[i][j] >= 2)
            {
                d = L[i][j];
                if (d & 1)
                    d--;
                res += min(d / 2, U[i][j]) - 1;
            }

            if (U[i][j] >= 4 && L[i][j] >= 2)
            {
                d = U[i][j];
                if (d & 1)
                    d--;
                res += min(d / 2, L[i][j]) - 1;
            }

            // left down
            if (L[i][j] >= 4 && D[i][j] >= 2)
            {
                d = L[i][j];
                if (d & 1)
                    d--;
                res += min(d / 2, D[i][j]) - 1;
            }

            if (D[i][j] >= 4 && L[i][j] >= 2)
            {
                d = D[i][j];
                if (d & 1)
                    d--;
                res += min(d / 2, L[i][j]) - 1;
            }
            // right up
            if (R[i][j] >= 4 && U[i][j] >= 2)
            {
                d = R[i][j];
                if (d & 1)
                    d--;

                res += min(d / 2, U[i][j]) - 1;
            }
            if (U[i][j] >= 4 && R[i][j] >= 2)
            {
                d = U[i][j];
                if (d & 1)
                    d--;
                res += min(d / 2, R[i][j]) - 1;
            }
            // right down
            if (R[i][j] >= 4 && D[i][j] >= 2)
            {
                d = R[i][j];
                if (d & 1)
                    d--;
                res += min(d / 2, D[i][j]) - 1;
            }

            if (D[i][j] >= 4 && R[i][j] >= 2)
            {
                d = D[i][j];
                if (d & 1)
                    d--;
                res += min(d / 2, R[i][j]) - 1;
            }
        }
    }
    return res;
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