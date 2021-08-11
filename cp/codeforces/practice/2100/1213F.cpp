// https://codeforces.com/contest/1213/problem/F
// Unstable String Sort

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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1), q(n + 1), mask(n + 1), pos(n + 1), ids;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> q[i];
    for (int i = 1; i <= n; i++)
        mask[p[i]] = i;
    for (int i = 1; i <= n; i++)
        q[i] = mask[q[i]];
    for (int i = 1; i <= n; i++)
        pos[q[i]] = i;
    stack<int> st;
    for (int i = 1; (int)ids.size() < k && i <= n; i++)
    {
        if (pos[i] >= i)
            st.push(pos[i]);
        while (!st.empty() && st.top() <= i)
            st.pop();
        if (st.empty())
            ids.pb(i);
    }
    int e = ids.size();
    if (e < k)
    {
        cout << "NO\n";
        return;
    }
    int cur = 1;
    char ch = 'a';
    vector<char> res(n + 1, 'z');
    for (int i : ids)
    {
        while (cur <= i)
        {
            res[p[cur]] = ch;
            cur++;
        }
        ch++;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << res[i];
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