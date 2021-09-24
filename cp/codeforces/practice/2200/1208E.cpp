// https://codeforces.com/contest/1208/problem/E
// Let Them Slide

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

const int inf = 1e9 + 7;
void solve()
{
    int n, w;
    cin >> n >> w;
    vector<vector<int>> arr(n);
    vector<int> len(n);
    vector<ll> res(w + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> len[i];
        arr[i].resize(len[i]);
        for (int j = 0; j < len[i]; j++)
            cin >> arr[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> st;
        multiset<int> ms;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        if (w <= 2 * len[i])
            st.resize(w);
        else
            st.resize(2 * len[i]);
        int mx = max(0, *max_element(arr[i].begin(), arr[i].end())), sz = (int)st.size();
        for (int j = 0; j < sz; j++)
        {
            st[j] = -inf;
            if (j >= len[i] || sz - j - 1 >= len[i])
                st[j] = 0;
            if (j < len[i])
            {
                ms.insert(arr[i][j]);
                pq.push({sz - len[i] + j, arr[i][j]});
            }
            st[j] = max(st[j], *ms.rbegin());
            while (!pq.empty() && pq.top().first == j)
            {
                ms.erase(ms.lower_bound(pq.top().second));
                pq.pop();
            }
        }
        if (w <= 2 * len[i])
        {
            for (int j = 0; j < sz; j++)
            {
                res[j] += st[j];
                res[j + 1] -= st[j];
            }
        }
        else
        {
            for (int j = 0; j < len[i]; j++)
            {
                res[j] += st[j];
                res[j + 1] -= st[j];
            }
            for (int j = sz - 1, t = 1; j >= len[i]; j--, t++)
            {
                res[w - t] += st[j];
                res[w - t + 1] -= st[j];
            }
            res[len[i]] += mx;
            res[w - len[i]] -= mx;
        }
    }
    for (int i = 1; i < w; i++)
        res[i] += res[i - 1];
    for (int i = 0; i < w; i++)
        cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}