// https://codeforces.com/contest/803/problem/F
// Coprime Subsequences

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5, MOD = 1e9 + 7;
// O(n)
vector<int> lp(N + 1), pr;
int mob[N], two[N];

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

void mobius()
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
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
            mob[i] = 1;
        else
        {
            if (lp[i / lp[i]] == lp[i])
                mob[i] = 0;
            else
                mob[i] = -1 * mob[i / lp[i]];
        }
    }
    two[0] = 1;
    for (int i = 1; i < N; i++)
        two[i] = mul(two[i - 1], 2);
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), freq(N), cnt(N), f(N);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            cnt[i] += freq[j];
    for (int i = 1; i < N; i++)
        f[i] = add(two[cnt[i]], -1);
    int res = 0;
    for (int i = 1; i < N; i++)
        res = add(res, mul(mob[i], f[i]));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mobius();
    cout << solve() << "\n";
    return 0;
}