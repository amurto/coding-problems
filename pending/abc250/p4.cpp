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

const int N = 2e6 + 5;
bool P[N];
int pre[N];

// O(root(n) * lognlogn)
void sieve()
{
    for (int i = 2; i < N; i++)
        P[i] = true;
    P[0] = P[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (!P[i])
            continue;
        for (int j = 2; i * j < N; j++)
            P[i * j] = false;
    }
    pre[0] = 0;
    for (int i = 1; i < N; i++)
        pre[i] = pre[i - 1] + P[i];
}

ll solve()
{
    ll n, res = 0;
    cin >> n;
    for (ll i = 1; i * i * i <= n; i++)
        if (P[i])
            res += pre[min(i - 1, n / (i * i * i))];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    cout << solve() << "\n";
    return 0;
}