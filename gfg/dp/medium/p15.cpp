// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0
// Largest square formed in a matrix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[51][51];
int LSQ(vector<vector<char>> &C, int i, int j)
{
    if (i < 0 || j < 0 || C[i][j] == '0')
        return 0;
    if (DP[i][j] < 0)
        DP[i][j] = 1 + min(LSQ(C, i - 1, j - 1), min(LSQ(C, i - 1, j), LSQ(C, i, j - 1)));
    return DP[i][j];
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> C(n, vector<char>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> C[i][j];
        memset(DP, -1, sizeof(DP));
        int MAX = 0;
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                if (C[i][j] == '1')
                    MAX = max(MAX, LSQ(C, i, j));
        cout << MAX << endl;
    }
    return 0;
}