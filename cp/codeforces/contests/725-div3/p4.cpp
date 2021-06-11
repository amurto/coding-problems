#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int x, y, k, op = 0, cntX = 0, cntY = 0;
    cin >> x >> y >> k;
    for (int i = 2; i * i <= max(x, y); i++)
    {
        while (x % i == 0 && y % i == 0)
        {
            x /= i;
            y /= i;
            op += 2;
        }
        while (x % i == 0)
        {
            x /= i;
            cntX++;
        }
        while (y % i == 0)
        {
            y /= i;
            cntY++;
        }
    }
    if (x > 1 && x == y)
        op += 2;
    else
    {
        if (x > 1)
            cntX++;
        if (y > 1)
            cntY++;
    }
    int mn = (cntX > 0) + (cntY > 0);
    int mx = cntX + cntY + op;
    if (k < mn || k > mx)
        return false;
    if (mn == 1 && k == 1)
        return true;
    return k != 1 && k <= mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}