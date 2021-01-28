// https://codeforces.com/contest/1237/problem/C2
// Balanced Removals (Harder)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5e4 + 1;
int p[N][3];
int solve(vector<int> &pt, int n, int k)
{
    if (k == 3)
        return pt[0];
    map<int, vector<int>> mp;
    for (int i : pt)
        mp[p[i][k]].pb(i);
    vector<int> rem;
    for (auto itr : mp)
    {
        int res = solve(itr.second, n, k + 1);
        if (res > -1)
            rem.pb(res);
    }
    for (int i = 1; i < rem.size(); i += 2)
        cout << rem[i - 1] + 1 << " " << rem[i] + 1 << "\n";
    if ((int)rem.size() % 2)
        return rem[rem.size() - 1];
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> p[i][j];
    vector<int> pt(n);
    for (int i = 0; i < n; i++)
        pt[i] = i;
    solve(pt, n, 0);
    return 0;
}