// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1861
// 10920 - Spiral Tap

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    int di[4] = {1, 0, -1, 0}, dj[4] = {0, -1, 0, 1};
    while (true)
    {
        cin >> n >> p;
        if (n == 0 && p == 0)
            break;
        int r = (n + 1) / 2, c = (n + 1) / 2, step = 0, dir = 0, cur = 1;
        while (cur < p)
        {
            if (dir % 2 == 0)
                step++;
            if (cur + step > p)
                step = p - cur;
            cur += step;
            r += step * di[dir % 4], c += step * dj[dir % 4];
            dir++;
        }
        cout << "Line = " << r << ", column = " << c << ".\n";
    }
    return 0;
}