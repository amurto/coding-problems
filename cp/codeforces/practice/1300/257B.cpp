// https://codeforces.com/contest/257/problem/B
// Playing Cubes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, chance = 1;
    vector<int> cube(2), col;
    cin >> cube[0] >> cube[1];
    if (cube[0] <= cube[1])
    {
        col.pb(0);
        cube[0]--;
    }
    else
    {
        col.pb(1);
        cube[1]--;
    }
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
    vector<int> sc(2);
    cout << col[0];
    for (int i = 1; i < col.size(); i++)
    {
        cout << col[i];
        if (col[i] == col[i - 1])
            sc[0]++;
        else
            sc[1]++;
    }
    cout << "\n";
    cout << sc[0] << " " << sc[1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}