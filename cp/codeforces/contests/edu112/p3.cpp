#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int m, sum = 1e9 + 5;
    cin >> m;
    vector<vector<int>> arr(2, vector<int>(m + 1)), pre(2, vector<int>(m + 1));
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= m; j++)
            pre[i][j] = arr[i][j] + pre[i][j-1];
    for (int j = 1; j <= m; j++)
        sum = min(sum, max(pre[0][m] - pre[0][j], pre[1][j - 1]));
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}