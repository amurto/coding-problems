// https://codeforces.com/contest/452/problem/C
// Magic Trick

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
        return 1.0;
    double p = 1.0 / n;
    return p + (1.0 - p) * (1.0 * (m - 1) / (n * m - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cout << solve() << "\n";
    return 0;
}