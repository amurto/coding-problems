#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int solve()
{
    int n, m, res = 1e9 + 5;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<pii> seq;
    for (int i = 0; i < n; i++)
        seq.pb({a[i], 0});
    for (int i = 0; i < m; i++)
        seq.pb({b[i], 1});
    sort(seq.begin(), seq.end());
    for (int i = 1; i < n + m; i++)
        if (seq[i - 1].second != seq[i].second)
            res = min(res, abs(seq[i].first - seq[i - 1].first));
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