#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 998244353, N = 65;
int w[N], jump[N], pos[N], hs[N], pw[N], ans[N];
set<int> st[N];

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

void set_data(int slots, int l, int r)
{
    for (int i = 0; i <= slots; i++)
        w[i] = hs[i] = 0;
    for (int i = slots, j = r; j >= l; i--, j--)
        w[i] = j;
}

void dfs(int cur, int f, int tw, int h)
{
    if (cur == 1)
    {
        if (f)
        {
            if (w[cur] == tw && hs[cur] == h)
                for (int i = N - 1; i > 0; i--)
                    ans[w[i]] = pos[i];
        }
        else
            st[w[cur]].insert(hs[cur]);
        return;
    }
    int l = cur - 1, r = cur, j = jump[cur];
    // l loses
    w[j] = w[r];
    hs[j] = add(add(hs[l], hs[r]), mul(w[l], pw[pos[l]]));
    dfs(cur - 2, f, tw, h);
    w[j] = 0;
    hs[j] = 0;
    // r loses
    w[j] = w[l];
    hs[j] = add(add(hs[l], hs[r]), mul(w[r], pw[pos[r]]));
    dfs(cur - 2, f, tw, h);
    w[j] = 0;
    hs[j] = 0;
}

void solve()
{
    int k, A, h;
    cin >> k >> A >> h;
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = mul(pw[i - 1], A);
    int mid = k - 1;
    jump[1] = 0;
    for (int i = 1; i < (1 << mid); i++)
        jump[2 * i] = jump[2 * i + 1] = i;
    int slots = (1 << k) - 1;
    pos[1] = 2;
    for (int i = 2, p = 2, cur = 2; i <= slots; i += p, p *= 2)
    {
        int tmp = cur;
        cur += p;
        for (int j = i; j < i + p; j++)
            pos[j] = tmp + 1;
    }
    set_data(slots, 1, (1 << k) / 2);
    dfs(slots, 0, 0, 0);
    set_data(slots, (1 << k) / 2 + 1, (1 << k));
    dfs(slots, 0, 0, 0);
    bool f = false;
    vector<pii> res;
    int tmp_hash = 0, req = 0, tw = 0;
    for (int i = 1; !f && i <= (1 << mid); i++)
    {
        for (int j = (1 << mid) + 1; !f && j <= (1 << k); j++)
        {
            for (int x : st[i])
            {
                // i wins
                tmp_hash = add(x, add(mul(i, pw[1]), mul(j, pw[2])));
                req = add(h, -tmp_hash);
                if (st[j].count(req))
                {
                    f = true;
                    res.pb({i, x});
                    res.pb({j, req});
                    tw = i;
                    break;
                }
                // j wins
                tmp_hash = add(x, add(mul(i, pw[2]), mul(j, pw[1])));
                req = add(h, -tmp_hash);
                if (st[j].count(req))
                {
                    f = true;
                    res.pb({i, x});
                    res.pb({j, req});
                    tw = j;
                    break;
                }
            }
        }
    }
    if (!f)
    {
        cout << "-1\n";
        return;
    }
    set_data(slots, 1, (1 << k) / 2);
    dfs(slots, 1, res[0].first, res[0].second);
    set_data(slots, (1 << k) / 2 + 1, (1 << k));
    dfs(slots, 1, res[1].first, res[1].second);
    ans[tw] = 1;
    for (int i = 1; i <= (1 << k); i++)
        cout << ans[i] << " ";
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