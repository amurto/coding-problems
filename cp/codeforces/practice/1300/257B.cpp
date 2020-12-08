// https://codeforces.com/contest/257/problem/B
// Playing Cubes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve(vector<int> cube, int f)
{
    int chance = 1;
    vector<int> col;
    col.pb(f);
    cube[f]--;
    while (cube[0] > 0 && cube[1] > 0)
    {
        int last = col.back();
        if (chance == 1)
            last ^= 1;
        col.pb(last);
        cube[last]--;
        chance ^= 1;
    }
    while (cube[0]-- > 0)
        col.pb(0);
    while (cube[1]-- > 0)
        col.pb(1);
    int sc = 0;
    for (int i = 1; i < col.size(); i++)
        if (col[i] == col[i - 1])
            sc++;
    return sc;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> cube(2);
    cin >> cube[0] >> cube[1];
    int p = max(solve(cube, 0), solve(cube, 1));
    cout << p << " " << cube[0] + cube[1] - p - 1 << "\n";
    return 0;
}