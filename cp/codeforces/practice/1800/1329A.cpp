// https://codeforces.com/contest/1329/problem/A
// Dreamoon Likes Coloring

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, shift = 0;
    cin >> n >> m;
    vector<int> arr(m), suf(m), pos(m);
    iota(pos.begin(), pos.end(), 1);
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        suf[i] = n - (i + arr[i]);
    for (int i = m - 2; i >= 0; i--)
        suf[i] = min(suf[i], suf[i + 1]);
    if (suf[0] < 0)
    {
        cout << "-1\n";
        return;
    }
    if (suf[0] == 0)
    {
        for (int p : pos)
            cout << p << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i < m; i++)
    {
        int rem = suf[i] - shift;
        pos[i] += shift;
        int last = pos[i];
        if (rem <= 0)
            continue;
        pos[i] = min(pos[i - 1] + 1 + rem, pos[i - 1] + arr[i - 1]);
        shift += pos[i] - last;
    }
    int mn = n;
    for (int i = 0; i < m; i++)
    {
        suf[i] = n - (pos[i] + arr[i] - 1);
        mn = min(mn, suf[i]);
    }
    if (mn != 0)
    {
        cout << "-1\n";
        return;
    }
    for (int p : pos)
        cout << p << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}