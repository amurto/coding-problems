#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e6 + 1;
bool P[N];
int C[N];

// O(nlognlogn)
void sieve()
{
    memset(P, true, sizeof(P));
    memset(C, 0, sizeof(C));
    P[0] = P[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (!P[i])
            continue;
        for (int j = 2; i * j < N; j++)
            P[i * j] = false;
    }
    int res = 0;
    for (int i = 5; i < N; i++)
    {
        if (P[i] && P[i - 2])
            res++;
        C[i] = res;
    }
}

int solve()
{
    int n;
    cin >> n;
    return C[n];
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