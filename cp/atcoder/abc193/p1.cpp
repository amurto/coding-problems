#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    double res = (a - b) * 100 * 1.0 / a;
    cout << setprecision(12) << fixed << res << "\n";
    return 0;
}