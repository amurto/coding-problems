#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m, op = 0;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++)
        cin >> t[i];
    int cur = 0;
    while (cur < m && t[cur] == s[0])
    {
        op++;
        cur++;
    }
    if (cur == m)
        return op;

    if (count(s.begin(), s.end(), t[cur]) == 0)
        return -1;
    int dis = n;
    for (int i = 1; i < n; i++)
        if (s[i] == t[cur])
            dis = min(dis, min(i, n - i));
    op += dis;
    op++;
    cur++;

    while (cur < m)
    {
        if (t[cur - 1] != t[cur])
            op++;
        op++;
        cur++;
    }
    return op;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}