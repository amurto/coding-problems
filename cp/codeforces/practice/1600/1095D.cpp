// https://codeforces.com/contest/1095/problem/D
// Circular Dance

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int common(int x1, int x2, int y1, int y2)
{
    if (x1 == y1 || x1 == y2)
        return x1;
    if (x2 == y1 || x2 == y2)
        return x2;
    return -1;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++)
        cin >> arr[i][0] >> arr[i][1];
    int p1 = 1, p2 = 0;
    if (common(arr[1][0], arr[1][1], arr[arr[1][0]][0], arr[arr[1][0]][1]) != -1)
        p2 = arr[1][0];
    else
        p2 = arr[1][1];
    vector<int> seq;
    while (p2 != 1)
    {
        int c = common(arr[p1][0], arr[p1][1], arr[p2][0], arr[p2][1]);
        seq.pb(p1);
        p1 = p2;
        p2 = c;
    }
    seq.pb(p1);
    for (int i = 0; i < n; i++)
        cout << seq[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}