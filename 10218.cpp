// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1159
// 10218 - Let's Dance !!!

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, w, c;
    while (cin >> m >> w >> c)
    {
        if (m == 0 && w == 0)
            break;
        double p = c * 1.0 / (m + w);
        double res = 0;
        for (int i = 0; i <= m; i++)
        {
            res += pow(p, i) * pow(1.0 - p, m - i);
        }
        cout << fixed << setprecision(5) << res << "\n";
    }
}