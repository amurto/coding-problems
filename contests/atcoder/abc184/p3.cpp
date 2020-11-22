#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int di[4] = {0, 3, 0, -3}, dj[4] = {3, 0, -3, 0};

bool check(int r1, int c1, int r2, int c2)
{
    for (int i = -2; i <= 2; i++)
    {
        for (int j = -2; j <= 2; j++)
        {
            int ii = r1 + i, jj = c1 + j;
            if (abs(ii - r2) == abs(jj - c2))
                return true;
        }
    }
    for (int dir = 0; dir < 4; dir++)
    {
        int ii = r1 + di[dir], jj = c1 + dj[dir];
        if (abs(ii - r2) == abs(jj - c2))
            return true;
    }
    return false;
}

int solve()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1 == r2 && c1 == c2)
        return 0;
    if ((abs(r1 - r2) == abs(c1 - c2)) || (abs(r1 - r2) + abs(c1 - c2) <= 3))
        return 1;
    if (check(r1, c1, r2, c2))
        return 2;
    if (abs(r1 + c1) % 2 == abs(r2 + c2) % 2)
        return 2;
    return 3;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}