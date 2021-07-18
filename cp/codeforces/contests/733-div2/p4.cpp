#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, k = 0;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), p(n + 1);
    vector<bool> in_deg(n + 1), out_deg(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // find loops (u->v and v->u)
    vector<pii> seq;
    for (int i = 1; i <= n; i++)
    {
        if (!out_deg[i] && i == a[a[i]])
        {
            seq.pb({i, a[i]});
            b[i] = a[i];
            b[a[i]] = i;
            in_deg[i] = in_deg[a[i]] = out_deg[i] = out_deg[a[i]] = true;
            k += 2;
            p[i] = a[i];
            p[a[i]] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!out_deg[i] && !in_deg[a[i]])
        {
            out_deg[i] = true;
            in_deg[a[i]] = true;
            k++;
            b[i] = a[i];
            p[a[i]] = i;
        }
    }
    vector<int> inq, outq;
    for (int i = 1; i <= n; i++)
    {
        if (!in_deg[i])
            inq.pb(i);
        if (!out_deg[i])
            outq.pb(i);
    }
    if (inq.size() == 1 && outq.size() == 1 && inq[0] == outq[0])
    {
        int cur = inq[0];
        b[cur] = cur;
        swap(b[cur], b[p[a[cur]]]);
        inq.clear();
        outq.clear();
    }
    if (!inq.empty())
    {
        int sz = inq.size();
        for (int i = 0; i < sz - 1; i++)
            if (inq[i] == outq[i])
                swap(outq[i], outq[i + 1]);
        if (inq[sz - 1] == outq[sz - 1])
            swap(outq[0], outq[sz - 1]);
        for (int i = 0; i < sz; i++)
            b[outq[i]] = inq[i];
    }
    cout << k << "\n";
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    cout << "\n";
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