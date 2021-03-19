// linear sieve

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e7;
bool P[N];

// O(root(n) * lognlogn)
void sieve()
{
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (!P[i])
            continue;
        for (int j = 2; i * j < N; j++)
            P[i * j] = false;
    }
}

// O(n)
vector<int> lp(N + 1), pr;
void linear_sieve()
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
}

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

int main()
{
    sieve();
    return 0;
}