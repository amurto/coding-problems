// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
// Number of Coins

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Recursion with Memo
int MC(int *C, int M, int V, int *DP)
{
    if (V == 0)
        return 0;
    if (DP[V] == -1)
    {
        int ans = INT_MAX;
        for (int i = M; i >= 0; i--)
        {
            if (C[i] <= V)
            {
                int sol = MC(C, M, V - C[i], DP);
                if (sol != INT_MAX)
                    ans = min(1 + sol, ans);
            }
        }
        DP[V] = ans;
    }
    return DP[V];
}

int minCoins(int coins[], int M, int V)
{
    int DP[V + 1];
    memset(DP, -1, sizeof(DP));
    int ans = MC(coins, M - 1, V, DP);
    ans = (ans == INT_MAX) ? -1 : ans;
    return ans;
}

// Bottom Up Approach
int minCoins(int coins[], int M, int V)
{
    int DP[V + 1];
    memset(DP, 0, sizeof(DP));
    DP[0] = 0;
    for (int i = 0; i < M; i++)
        for (int j = coins[i]; j <= V; j++)
            if (j - coins[i] == 0 || DP[j - coins[i]] > 0)
                DP[j] = (DP[j] == 0) ? 1 + DP[j - coins[i]] : min(DP[j], 1 + DP[j - coins[i]]);
    return (DP[V] == 0) ? -1 : DP[V];
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int V, M;
        cin >> V >> M;
        int coins[M];
        for (int i = 0; i < M; i++)
            cin >> coins[i];
        cout << minCoins(coins, M, V) << endl;
    }
    return 0;
}