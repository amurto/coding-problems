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

const int N = 2e5 + 5;
int arr[12][N];
set<vector<int>> st, vis;
int mx = 0;
vector<int> best;
void dfs(vector<int> &cur, int n)
{
    vector<pii> seq;
    for (int i = 0; i < n; i++)
        if (cur[i] - 1 >= 0)
            seq.pb({arr[i][cur[i] - 1], i});
    sort(seq.rbegin(), seq.rend());
    for (pii p : seq)
    {
        cur[p.second]--;
        if (!vis.count(cur))
        {
            vis.insert(cur);
            if (!st.count(cur))
            {
                int sum = 0;
                for (int i = 0; i < n; i++)
                    sum += arr[i][cur[i]];
                if (sum > mx)
                {
                    mx = sum;
                    best = cur;
                }
            }
            else
                dfs(cur, n);
        }
        cur[p.second]++;
    }
}
void solve()
{
    int n, m, c;
    cin >> n;
    vector<int> cur(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        cur[i] = c - 1;
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];
    }
    cin >> m;
    vector<vector<int>> banned(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> banned[i][j];
            banned[i][j]--;
        }
        st.insert(banned[i]);
    };
    if (!st.count(cur))
    {
        for (int i = 0; i < n; i++)
            mx += arr[i][cur[i]];
        best = cur;
    }
    else
    {
        vis.insert(cur);
        dfs(cur, n);
    }
    for (int i = 0; i < n; i++)
        cout << best[i] + 1 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}