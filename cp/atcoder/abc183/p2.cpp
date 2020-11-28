#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    double res = (gx * sy + gy * sx) / (gy + sy);
    cout << setprecision(16) << res << "\n";
    return 0;
}