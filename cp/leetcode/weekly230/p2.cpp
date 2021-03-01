#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void recur(vector<int> &toppingCosts, vector<int> &baseCosts, int cur, int sum, int target, int &res, int &close)
{
    if (cur == toppingCosts.size())
    {
        for (int j = 0; j < baseCosts.size(); j++)
        {
            sum += baseCosts[j];
            if (abs(target - sum) < close || ((abs(target - sum)) == close && sum < res))
            {
                close = abs(target - sum);
                res = sum;
            }
            sum -= baseCosts[j];
        }
        return;
    }
    for (int i = 0; i <= 2; i++)
        recur(toppingCosts, baseCosts, cur + 1, sum + i * toppingCosts[cur], target, res, close);
}

int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
{
    int res = 1e6, close = 1e6;
    recur(toppingCosts, baseCosts, 0, 0, target, res, close);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, target;
    cin >> n >> m >> target;
    vector<int> baseCosts(n), toppingCosts(m);
    for (int i = 0; i < n; i++)
        cin >> baseCosts[i];
    for (int i = 0; i < m; i++)
        cin >> toppingCosts[i];
    cout << closestCost(baseCosts, toppingCosts, target) << "\n";
    return 0;
}