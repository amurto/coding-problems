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
    int n, dmg, res = 0;
    cin >> n >> dmg;
    vector<int> L(n), R(n), ids1(n), ids2(n), vis(n);
    for (int i = 0; i < n; i++)
        cin >> L[i] >> R[i];
    iota(ids1.begin(), ids1.end(), 0);
    iota(ids2.begin(), ids2.end(), 0);
    sort(ids1.begin(), ids1.end(), [&](int &i1, int &i2)
         { return L[i1] < L[i2]; });
    sort(ids2.begin(), ids2.end(), [&](int &i1, int &i2)
         { return R[i1] < R[i2]; });
    for (int i = 0, j = 0; i < n; i++)
    {
        int id = ids2[i];
        if (!vis[id])
        {
            while (j < n && L[ids1[j]] <= R[id] + dmg-1)
            {
                vis[ids1[j]] = 1;
                j++;
            }
            res++;
        }
    }
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