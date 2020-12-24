// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1917
// 10976 - Fractions Again?!

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    while (cin >> k)
    {
        vector<pair<int, int>> res;
        for (int i = k + 1; i <= 2 * k; i++)
        {
            int x = i;
            if ((x * k) % (x - k) == 0)
            {
                int y = (x * k) / (x - k);
                res.pb({y, x});
            }
        }
        cout << res.size() << "\n";
        for (pair<int, int> r : res)
            cout << "1/" << k << " = 1/" << r.first << " + 1/" << r.second << "\n";
    }
    return 0;
}