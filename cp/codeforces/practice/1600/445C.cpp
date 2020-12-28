// https://codeforces.com/contest/445/problem/C
// DZY Loves Physics

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    double res = 0;
    vector<int> C(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> C[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        res = max(res, (C[a] + C[b]) * 1.0 / c);
    }
    cout << fixed << setprecision(15) << res << "\n";
    return 0;
}