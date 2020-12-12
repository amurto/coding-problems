// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=284
// 348 - Optimal Array Multiplication Sequence

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

string sequence(vector<vector<int>> &dir, int L, int R)
{
    if (L == R)
        return "A" + to_string(L + 1);
    return "(" + sequence(dir, L, dir[L][R]) + " x " + sequence(dir, dir[L][R] + 1, R) + ")";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t = 1;
    while (cin >> n && n)
    {
        vector<pii> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)), dir(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;
        for (int gap = 1; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                for (int k = i; k < j; k++)
                {   
                    int cur = dp[i][k] + dp[k + 1][j] + arr[i].first * arr[k].second * arr[j].second;
                    if (cur < dp[i][j])
                    {
                        dp[i][j] = cur;
                        dir[i][j] = k;
                    }
                }
            }
        }
        cout << "Case " << t << ": " << sequence(dir, 0, n - 1) << "\n";
        t++;
    }
    return 0;
}