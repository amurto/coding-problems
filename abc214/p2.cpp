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

int solve()
{
    int s, t, res = 0;
    cin >> s >> t;
    for (int i = 0; i <= s; i++)
        for (int j = 0; j <= s; j++)
            for (int k = 0; k <= s; k++)
                res += (i + j + k <= s && i * j * k <= t);
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