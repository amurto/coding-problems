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

const int N = 4e5 + 5;
int arr[N], lv[N], rv[N], cnt[3 * N];
ll ans[N];
vector<int> g[N];

class node
{
public:
    int l = 0, r = 0, id = 0;
    node() {}
    node(int l, int r, int id) : l(l), r(r), id(id) {}
    bool operator<(const node &other) const
    {
        if (r == other.r)
            return l > other.l;
        return r < other.r;
    }
};

void sack(int cur, int last, int x, bool keep)
{
    ans[cur] = 0;
    int mx = -1, big = -1;
    for (int e : g[cur])
        if (e != last && rv[e] - lv[e] + 1 > mx)
            mx = rv[e] - lv[e] + 1, big = e;
    for (int e : g[cur])
        if (e != last && e != big)
            sack(e, cur, x, false);
    int l = rv[cur] + 1, r = rv[cur] + 1;
    if (big != -1)
    {
        sack(big, cur, x, true);
        l = lv[big];
        r = rv[big];
        ans[cur] += ans[big];
    }
    for (int i = lv[cur]; i < l; i++)
    {
        ans[cur] += 1ll * cnt[x - arr[i]];
        cnt[arr[i]]++;
    }
    for (int i = r + 1; i <= rv[cur]; i++)
    {
        ans[cur] += 1ll * cnt[x - arr[i]];
        cnt[arr[i]]++;
    }
    if (!keep)
        for (int i = lv[cur]; i <= rv[cur]; i++)
            cnt[arr[i]]--;
}

ll solve()
{
    int n, x, q;
    cin >> n >> x;
    memset(cnt, 0, sizeof(cnt));
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]] = 0;
    }
    cin >> q;
    vector<pii> qs(q + 1);
    qs[0].second = n;
    for (int i = 1; i <= q; i++)
        cin >> qs[i].first >> qs[i].second;
    sort(qs.begin(), qs.end());
    vector<node> ivs;
    for (int i = 0, id = 0; i <= q;)
    {
        int j = i;
        while (j <= q && qs[i].first == qs[j].first && qs[i].second == qs[j].second)
            j++;
        if ((j - i) & 1)
        {
            ivs.pb(node(qs[i].first, qs[i].second, id));
            lv[id] = qs[i].first;
            rv[id] = qs[i].second;
            id++;
        }
        i = j;
    }
    sort(ivs.begin(), ivs.end());
    int sz = ivs.size();
    stack<node> st;
    for (node iv : ivs)
    {
        while (!st.empty() && st.top().l >= iv.l && st.top().r <= iv.r)
        {
            g[iv.id].pb(st.top().id);
            st.pop();
        }
        st.push(iv);
    }
    sack(0, 0, x, true);
    ll res = 0;
    for (int i = 1; i < sz; i++)
        res ^= ans[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}