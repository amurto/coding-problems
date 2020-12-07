// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
// 562 - Dividing coins

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dp[101][50001];

int dc(vector<int> &coin, int cur, int sf, int sum)
{
    if (cur == coin.size())
        return abs(sf - (sum - sf));
    if (dp[cur][sf] == -1)
        dp[cur][sf] = min(dc(coin, cur + 1, sf, sum), dc(coin, cur + 1, sf + coin[cur], sum));
    return dp[cur][sf];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<int> coin(n);
        for (int i = 0; i < n; i++)
            cin >> coin[i];
        int sum = 0;
        for (int c : coin)
            sum += c;
        memset(dp, -1, sizeof(dp));
        cout << dc(coin, 0, 0, sum) << "\n";
    }
    return 0;
}