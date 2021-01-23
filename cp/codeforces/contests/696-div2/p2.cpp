#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e7 + 1;
bool P[N];
vector<int> p;

// O(nlognlogn)
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
    for (int i = 2; i < N; i++)
        if (P[i])
            p.pb(i);
}

int solve()
{
    int d;
    cin >> d;
    int a = lower_bound(p.begin(), p.end(), 1 + d) - p.begin();
    a = p[a];
    int b = lower_bound(p.begin(), p.end(), a + d) - p.begin();
    b = p[b];
    return a * b;
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