// https://codeforces.com/contest/253/problem/C
// Text Editor

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int min_range(vector<int> &ch, int i, int j)
{
    int mn = ch[i];
    for (int r = i; r <= j; r++)
        mn = min(mn, ch[r]);
    return mn;
}
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int n, r1, c1, r2, c2;
    cin >> n;
    vector<int> ch(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> ch[i];
        ch[i]++;
    }
    cin >> r1 >> c1 >> r2 >> c2;
    int dis = INT_MAX;
    for (int i = 1; i <= n; i++)
        dis = min(dis, abs(r1 - i) + abs(r2 - i) + abs(c2 - min(c1, min_range(ch, min({r1, i, r2}), max({r1, i, r2})))));
    cout << dis << "\n";
    return 0;
}