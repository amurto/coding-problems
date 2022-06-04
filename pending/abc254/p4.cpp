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

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<int> sq(n + 1), cnt(n + 1);
    iota(sq.begin(), sq.end(), 0);
    for (int i = 2; i * i <= n; i++)
    {
        int t = i * i;
        for (int j = t; j <= n; j += t)
            while (sq[j] % t == 0)
                sq[j] /= t;
    }
    for (int i = 1; i <= n; i++)
        cnt[sq[i]]++;
    for (int i = 1; i <= n; i++)
        res += (cnt[i] * 1ll * cnt[i]);
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