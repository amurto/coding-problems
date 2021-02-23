// https://codeforces.com/contest/552/problem/C
// Vanya and Scales

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool recur(int t, int w, int m);
bool pos(int t, int w, int m);

bool recur(int t, int w, int m)
{
    if (m == 0)
        return true;
    if (t == 0 || m % w > 0)
        return false;
    return pos(t, w, m / w);
}

bool pos(int t, int w, int m)
{
    return m == 1 || recur(t - 1, w, m - 1) || recur(t - 1, w, m) || recur(t - 1, w, m + 1);
}

bool solve()
{
    int w, m;
    cin >> w >> m;
    return pos(101, w, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}