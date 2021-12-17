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

int ask = 0;
int query(int a, int b, int c)
{
    cout << "? " << a << " " << b << " " << c << endl;
    int ans;
    cin >> ans;
    ask++;
    if (ans == -1)
        exit(0);
    return ans;
}

void solve()
{
    ask = 0;
    int n;
    cin >> n;
    vector<int> Q(n + 1), col(n + 1, -1), res;
    array<int, 2> idx{0, 0};
    for (int i = 3; i <= n; i += 3)
    {
        Q[i] = query(i - 2, i - 1, i);
        idx[Q[i]] = i;
    }
    int imp = -1, crew = -1;
    for (int j = idx[1] - 2; j <= idx[1] - 1; j++)
    {
        int ans = query(idx[0] - 2, idx[0] - 1, j);
        if (ans == 1)
            crew = j;
    }
    if (crew == -1)
    {
        imp = idx[0] - 2;
        int ans1 = query(imp, idx[1] - 2, idx[1] - 1), ans2 = query(imp, idx[1] - 1, idx[1]), ans3 = query(imp, idx[1] - 2, idx[1]);
        if (ans1 == 1)
            crew = idx[1] - 1;
        if (ans2 == 1)
            crew = idx[1];
        if (ans3 == 1)
            crew = idx[1] - 2;
    }
    else
    {
        int ans1 = query(crew, idx[0] - 2, idx[0] - 1), ans2 = query(crew, idx[0] - 1, idx[0]), ans3 = query(crew, idx[0] - 2, idx[0]);
        if (ans1 == 0)
            imp = idx[0] - 1;
        if (ans2 == 0)
            imp = idx[0];
        if (ans3 == 0)
            imp = idx[0] - 2;
    }
    col[imp] = 0;
    col[crew] = 1;
    array<int, 2> vals{imp, crew};
    for (int i = 3; i <= n; i += 3)
    {
        int a = i - 2, b = i - 1, c = i;
        if (a == vals[0] || b == vals[0] || c == vals[0] || a == vals[1] || b == vals[1] || c == vals[1])
        {
            for (int t = i - 2; t <= i; t++)
                if (t != vals[0] && t != vals[1])
                    col[t] = query(t, vals[0], vals[1]);
        }
        else
        {
            int tmp = Q[i] ^ 1;
            int q1 = query(vals[tmp], a, b), q2 = query(vals[tmp], b, c);
            col[a] = col[b] = col[c] = Q[i];
            if (q1 == tmp && q2 == tmp)
                col[b] = tmp;
            else if (q1 == tmp)
                col[a] = tmp;
            else if (q2 == tmp)
                col[c] = tmp;
        }
    }
    for (int i = 1; i <= n; i++)
        if (col[i] == 0)
            res.pb(i);
    cout << "! " << (int)res.size() << " ";
    for (int id : res)
        cout << id << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}