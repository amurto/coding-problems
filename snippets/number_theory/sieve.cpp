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

int mob[N];
void mobius()
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
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
            mob[i] = 1;
        else
        {
            if (lp[i / lp[i]] == lp[i])
                mob[i] = 0;
            else
                mob[i] = -1 * mob[i / lp[i]];
        }
    }
}

// Segmented Sieve
// Returns biggest prime for each number from l to r
// r-l+1 should not be too big
vector<ll> segmented_sieve(ll l, ll r)
{
    int sz = r - l + 1;
    vector<ll> big_pr(sz);
    for (int i = 0; i < sz; i++)
        big_pr[i] = l + i;
    for (int x : pr)
        for (ll i = x * 1ll * ((l + x - 1) / x); i <= r; i += x)
            while (big_pr[i - l] % x == 0)
                big_pr[i - l] /= x;
    return big_pr;
}

int main()
{
    sieve();
    vector<ll> big_pr = segmented_sieve(1000000, 2000000);
    return 0;
}