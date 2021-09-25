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

const int N = 1e6 + 5;
bool P[N];
int cnt[N];
// O(root(n) * lognlogn)
// Store number of distinct prime factors for every number
void distinct_primes()
{
    memset(P, true, sizeof(P));
    memset(cnt, 0, sizeof(cnt));
    P[0] = P[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (!P[i])
            continue;
        cnt[i] = 1;
        for (int j = 2; i * j < N; j++)
        {
            P[i * j] = false;
            cnt[i * j]++;
        }
    }
}

void solve()
{
    ll n, a = 0, b = 0;
    cin >> n;
    if (n % 2 == 0)
    {
        a = 2 * n;
        b = n;
    }
    for (ll i = 3; a == 0 && i < N; i++)
    {
        if (cnt[i - 1] == cnt[i] && __gcd(i - 1, n) == 1 && __gcd(i, n) == 1)
        {
            a = n * i;
            b = n * (i - 1);
        }
    }
    cout << a << " " << b << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    distinct_primes();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}