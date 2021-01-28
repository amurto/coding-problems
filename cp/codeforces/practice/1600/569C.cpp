// https://codeforces.com/contest/569/problem/C
// Primes or Palindromes?

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e7 + 1;
vector<int> pr(N, 1), rub(N), ten(4);

// O(nlognlogn)
void sieve()
{
    pr[0] = pr[1] = 0;
    for (int i = 2; i * i < N; i++)
    {
        if (pr[i] == 0)
            continue;
        for (int j = 2; i * j < N; j++)
            pr[i * j] = 0;
    }
    for (int i = 1; i < N; i++)
        pr[i] += pr[i - 1];
}

void recur(int cur, int sz)
{
    if (sz == 4)
        return;
    int tmp = cur, rev = 0;
    while (tmp > 0)
    {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    rub[cur * ten[sz] + rev] = 1;

    for (int i = 0; i <= 9; i++)
    {
        rub[(cur * 10 + i) * ten[sz] + rev] = 1;
        recur(cur * 10 + i, sz + 1);
    }
}
void init()
{
    ten[0] = 1;
    for (int i = 1; i < 4; i++)
        ten[i] = ten[i - 1] * 10;
    rub[0] = 0;
    for (int i = 1; i <= 9; i++)
    {
        recur(i, 1);
        rub[i] = 1;
    }
    for (int i = 1; i < N; i++)
        rub[i] += rub[i - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    sieve();
    int p, q, l = 0, r = N - 1, res = -1;
    cin >> p >> q;
    int g = __gcd(p, q);
    p /= g;
    q /= g;
    for (int i = 1; i < N; i++)
        if (q * 1ll * pr[i] <= p * 1ll * rub[i])
            res = i;
    res < 0 ? cout << "Palindromic tree is better than splay tree\n" : cout << res << "\n";
    return 0;
}