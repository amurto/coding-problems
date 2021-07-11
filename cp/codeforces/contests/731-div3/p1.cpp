#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int dis = abs(x2 - x1) + abs(y2 - y1);
    if (x1 == x2 && x1 == x3)
    {
        if (y1 > y2)
            swap(y1, y2);
        if (y3 >= y1 && y3 <= y2)
            dis += 2;
    }
    else if (y1 == y2 && y2 == y3)
    {
        if (x1 > x2)
            swap(x1, x2);
        if (x3 >= x1 && x3 <= x2)
            dis += 2;
    }
    return dis;
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