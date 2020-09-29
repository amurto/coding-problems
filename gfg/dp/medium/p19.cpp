// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
// Maximum Profit

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int MP(vector<vector<int>> &DP, vector<int> &A, int cur, int K, int N)
{
    if (cur == N || K == 0)
        return 0;
    if (DP[cur][K] < 0)
    {
        DP[cur][K] = 0;
        for (int i = cur + 1; i < N; i++) {
            if (A[i] > A[cur])
                DP[cur][K] = max(DP[cur][K], A[i] - A[cur] + MP(DP, A, i + 1, K - 1, N));
        }
        DP[cur][K] = max(DP[cur][K], MP(DP, A, cur + 1, K, N));
    }
    return DP[cur][K];
}

int maxProfit(int k, vector<int>& prices) {
    if (2*k>prices.size()) {
        int profit=0;
        for (int i=1; i<prices.size(); i++)
            if (prices[i]>prices[i-1])
                profit = profit + prices[i] - prices[i-1];
        return profit;
    }
    vector<vector<int>> DP(prices.size(), vector<int>(k+1, -1));
    return MP(DP, prices, 0, k, prices.size());
}

int main()
{
    int N, K, v;
    cin >> K >> N;
    vector<int> prices;
    for (int i = 0; i < N; i++) {
        cin>>v;
        prices.pb(v);
    }
    cout << maxProfit(K, prices) << endl;
    return 0;
}