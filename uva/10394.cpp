// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1335
// 10394 - Twin Primes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e7;
bool P[N];
vector<pair<int, int>> tp;

// O(nlognlogn)
void sieve()
{
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (!P[i])
            continue;
        for (int j = 2; i * j < N; j++)
            P[i * j] = false;

        if (P[i - 2] && P[i])
            tp.pb({i - 2, i});
    }
}
int main()
{
    sieve();
    int n;
    while (cin >> n)
        cout << "(" << tp[n - 1].first << ", " << tp[n - 1].second << ")\n";
    return 0;
}