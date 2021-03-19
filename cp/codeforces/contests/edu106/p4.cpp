#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e7 + 5;
bool P[N];
int cnt[N];

// O(root(n) * lognlogn)
void sieve()
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

int f(int c, int d, int r)
{
    if ((d + r) % c == 0)
        return 1 << cnt[(d + r) / c];
    return 0;
}

int solve()
{
    int c, d, x, res = 0;
    cin >> c >> d >> x;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            res += f(c, d, x / i);
            if ((i * i) != x)
                res += f(c, d, i);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}