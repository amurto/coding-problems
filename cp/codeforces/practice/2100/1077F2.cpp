// https://codeforces.com/contest/1077/problem/F2
// Pictures with Kittens (hard version)

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back

const ll inf = 1e15;

void insert(deque<pii> &dq, pii e)
{
    while (!dq.empty() && dq.back().first <= e.first)
        dq.pop_back();
    dq.push_back(e);
}

void remove(deque<pii> &dq, pii e)
{
    if (!dq.empty() && dq.front().second == e.second)
        dq.pop_front();
}

ll solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> arr(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -inf));
    vector<deque<pii>> dq(x + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    dp[0][0] = 0;
    insert(dq[0], {0, 0});
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(x, i); j > 0; j--)
        {
            if (!dq[j - 1].empty())
                dp[i][j] = dq[j - 1].front().first + arr[i];
            if (i - k > 0 && dp[i - k][j] >= 0)
                remove(dq[j], {dp[i - k][j], i - k});
            if (dp[i][j] >= 0)
                insert(dq[j], {dp[i][j], i});
        }
        if (i - k == 0)
            dq[0].pop_front();
    }
    insert(dq[x], {-inf, n + 1});
    ll res = dq[x].front().first;
    return res < 0 ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}