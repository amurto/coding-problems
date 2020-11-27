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

pair<int, int> solve(int n)
{
    for (int L = 2, R = n - 2; L <= R; L++, R--)
        if (P[L] && P[R])
            return {L, R};
    return {-1, -1};
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    sieve();
    int n;
    while (cin >> n)
    {
        vector<pair<int, int>> res;
        if (n % 2 == 1)
        {
            if (n < 9)
            {
                cout << "Impossible\n";
                continue;
            }
            n -= 5;
            res.pb({2, 3});
        }
        else
        {
            if (n < 8)
            {
                cout << "Impossible\n";
                continue;
            }
            n -= 4;
            res.pb({2, 2});
        }
        res.pb(solve(n));
        for (pair<int, int> p : res)
            cout << p.first << " " << p.second << " ";
        cout << "\n";
    }
    return 0;
}