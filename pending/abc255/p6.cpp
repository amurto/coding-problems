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
    int n;
    cin >> n;
    vector<int> pre(n), in(n), tin(n + 1), L(n + 1), R(n + 1), st, seq1, seq2;
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        tin[in[i]] = i;
    }
    if (pre[0] != 1)
    {
        cout << "-1\n";
        return;
    }
    st.pb(1);
    for (int i = 1; i < n; i++)
    {
        int cur = pre[i];
        if (tin[pre[i - 1]] > tin[cur])
        {
            L[pre[i - 1]] = cur;
            st.pb(cur);
        }
        else
        {
            if (st.empty())
            {
                cout << "-1\n";
                return;
            }
            int sz = (int)st.size();
            int low = 0, high = sz - 1, id = sz - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (tin[st[mid]] <= tin[cur])
                {
                    id = min(id, mid);
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            R[st[id]] = cur;
            int p = st[id];
            while (st.back() != p)
                st.pop_back();
            st.pop_back();
            st.pb(cur);
        }
    }
    auto pre_dfs = [&](const auto &self, int cur) -> void
    {
        seq1.pb(cur);
        if (L[cur] > 0)
            self(self, L[cur]);
        if (R[cur] > 0)
            self(self, R[cur]);
    };
    auto in_dfs = [&](const auto &self, int cur) -> void
    {
        if (L[cur] > 0)
            self(self, L[cur]);
        seq2.pb(cur);
        if (R[cur] > 0)
            self(self, R[cur]);
    };
    pre_dfs(pre_dfs, 1);
    in_dfs(in_dfs, 1);
    if (pre != seq1 || in != seq2)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        cout << L[i] << " " << R[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}