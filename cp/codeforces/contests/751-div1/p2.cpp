#ifdef use_debug
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
    int n, dis = 1;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), reach(n + 1, -1), from(n + 1, -1), drop(n + 1, -1), del;
    // reach[i] = j -> "j" jumps needed to reach i
    // from[i] = j -> frog jumped from j to i
    // drop[i] = j -> frog dropped from j to i
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(i);
    reach[n] = 0;
    from[n] = drop[n] = n;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        queue<int> tmp;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            int g = max(0, cur - a[cur]);
            auto it = st.lower_bound(g);
            for (auto i = it; i != st.end() && *i <= cur; i++)
            {
                del.pb(*i);
                from[*i] = cur;
                tmp.push(*i);
                reach[*i] = dis;
            }
            for (int x : del)
                st.erase(x);
            del.clear();
        }
        while (!tmp.empty())
        {
            int cur = tmp.front();
            tmp.pop();
            if (drop[cur + b[cur]] == -1)
            {
                drop[cur + b[cur]] = cur;
                q.push(cur + b[cur]);
            }
        }
        dis++;
    }
    if (reach[0] == -1)
    {
        cout << "-1\n";
        return;
    }
    cout << reach[0] << "\n";
    vector<int> path;
    path.pb(0);
    int cur = drop[from[0]];
    while (cur != n)
    {
        path.pb(cur);
        cur = drop[from[cur]];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}