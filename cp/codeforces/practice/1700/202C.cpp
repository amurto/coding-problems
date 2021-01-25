// https://codeforces.com/contest/202/problem/C
// Clear Symmetry

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool pos1(int n, int x)
{
    int c = (n * n + 1) / 2;
    int o = 1, t = (n / 4) * 2;
    int r = (c - o - t * 2) / 4;
    for (int i = 0; i <= o; i++)
        for (int j = 0; j <= t; j++)
            for (int k = 0; k <= r; k++)
                if (i * 1 + j * 2 + k * 4 == x)
                    return true;
    return false;
}

bool pos2(int n, int x)
{
    int c = n * n - (n * n + 1) / 2;
    int o = 0, t = ((n + 1) / 4) * 2;
    int r = (c - o - t * 2) / 4;
    for (int i = 0; i <= o; i++)
        for (int j = 0; j <= t; j++)
            for (int k = 0; k <= r; k++)
                if (i * 1 + j * 2 + k * 4 == x)
                    return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, c = 1;
    cin >> x;
    while (!pos1(c, x) && !pos2(c, x))
        c += 2;
    cout << c << "\n";
    return 0;
}