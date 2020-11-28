// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1109
// 10168 - Summation of Four Primes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e7 + 1;
bool P[N];

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
    }
}

void goldbach(int n)
{
    for (int i = 2;; i++)
        if (P[i] && P[n - i])
        {
            cout << i << " " << n - i << "\n";
            return;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int n;
    while (cin >> n)
    {
        if (n < 8)
        {
            cout << "Impossible.\n";
            continue;
        }
        if (n % 2 == 1)
        {
            n -= 5;
            cout << 2 << " " << 3 << " ";
        }
        else
        {
            n -= 4;
            cout << 2 << " " << 2 << " ";
        }
        goldbach(n);
    }
    return 0;
}