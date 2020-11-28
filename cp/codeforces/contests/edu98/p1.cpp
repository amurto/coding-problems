#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve(int x, int y)
{
    if (x == 0 && y == 0)
        return 0;
    else if (x == 0)
        return y + y - 1;
    else if (y == 0)
        return x + x - 1;
    else
    {
        int i = 0, j = 0, d = 0;
        while (i != x && j != y)
        {
            i++;
            j++;
            d += 2;
        }
        if (j != y)
            d += abs(y - j) + abs(y - j) - 1;
        else if (i != x)
            d += abs(x - i) + abs(x - i) - 1;
        return d;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    return 0;
}