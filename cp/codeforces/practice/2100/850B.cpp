// https://codeforces.com/contest/850/problem/B
// Arpa and a list of numbers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5;

// O(n)
vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

ll solve()
{
    int n, v;
    ll x, y, ones = 0;
    cin >> n >> x >> y;
    int inc = x / y;
    ll res = x * n;
    vector<int> arr(n), pre(2 * N);
    vector<ll> sum(2 * N);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pre[arr[i]]++;
        sum[arr[i]] += 1ll * arr[i];
    }
    for (int i = 1; i < 2 * N; i++)
    {
        pre[i] += pre[i - 1];
        sum[i] += sum[i - 1];
    }
    for (int p : pr)
    {
        ll cost = 0;
        int mx = (N + p - 1) / p;
        for (int j = p; j <= mx * p; j += p)
        {
            int prev = j - p;
            int idx = max(prev, j - (inc + 1));
            cost += x * (pre[idx] - pre[prev]);
            cost += y * (((pre[j] - pre[idx]) * 1ll * j) - (sum[j] - sum[idx]));
        }
        res = min(res, cost);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    cout << solve() << "\n";
    return 0;
}