// https://codeforces.com/contest/400/problem/C
// Inna and Huge Candy Matrix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void rotate(int &i, int &j, int n, int m, int x, int y, int z)
{
    while (x-- > 0)
    {
        swap(i, j);
        swap(n, m);
        j = m + 1 - j;
    }
    if (y)
        j = m + 1 - j;
    while (z-- > 0)
    {
        swap(i, j);
        swap(n, m);
        i = n + 1 - i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y, z, p, i, j;
    cin >> n >> m >> x >> y >> z >> p;
    x %= 4;
    y %= 2;
    z %= 4;
    for (int itr = 0; itr < p; itr++)
    {
        cin >> i >> j;
        rotate(i, j, n, m, x, y, z);
        cout << i << " " << j << "\n";
    }
    return 0;
}