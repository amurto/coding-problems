#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double solve()
{
    int n;
    cin >> n;
    double res = 0;
    for (int j = n - 1; j >= 1; j--)
        res += n * 1.0 / j;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12) << solve() << "\n";
    return 0;
}