#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;

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

int solve()
{
    int n, k, res = 1;
    cin >> n >> k;
    vector<char> ch(k + 1);
    vector<int> pos(k + 1), arr(n + 1), dL(n + 1), dR(n + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> ch[i] >> pos[i];
        arr[pos[i]] = i;
        if (ch[i] == 'L')
        {
            dR[n]++;
            dR[pos[i]]--;
        }
        else
        {
            dL[1]++;
            dL[pos[i]]--;
        }
    }
    for (int i = 2; i <= n; i++)
        dL[i] += dL[i - 1];
    for (int i = n - 1; i > 0; i--)
        dR[i] += dR[i + 1];
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            int cnt = dL[i] + dR[i];
            res = mul(res, cnt);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}