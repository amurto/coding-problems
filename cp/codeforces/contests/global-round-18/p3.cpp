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

const int inf = 1e9 + 7;

int calc(int c01, int c10)
{
    if (c01 == 0 && c10 == 0)
        return 0;
    if (c01 == c10)
        return 2 * c01;
    return inf;
}

int solve()
{
    int n, res = inf;
    string a, b;
    cin >> n >> a >> b;
    vector<vector<int>> cnt(2, vector<int>(2));
    for (int i = 0; i < n; i++)
        cnt[b[i] - '0'][a[i] - '0']++;
    res = min(res, calc(cnt[0][1], cnt[1][0]));
    if (cnt[0][1] > 0)
        res = min(res, 1 + calc(cnt[0][0] + 1, cnt[1][1]));
    if (cnt[1][1] > 0)
        res = min(res, 1 + calc(cnt[0][0], cnt[1][1] - 1));
    return res >= inf ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}