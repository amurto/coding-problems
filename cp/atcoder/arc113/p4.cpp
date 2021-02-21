#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

set<string> st;
void dfs(vector<vector<int>> &arr, vector<pii> &seq, int cur, int n, int m, int lb, int rb)
{
    if (cur == seq.size())
    {
        string res;
        for (int i = 0; i < n; i++)
        {
            int mx = 0;
            for (int j = 0; j < m; j++)
                mx = max(mx, arr[i][j]);
            res.pb(char(mx + '0'));
        }
        for (int j = 0; j < m; j++)
        {
            int mn = 1e5;
            for (int i = 0; i < n; i++)
                mn = min(mn, arr[i][j]);
            res.pb(char(mn + '0'));
        }
        st.insert(res);
        return;
    }
    int r = seq[cur].first, c = seq[cur].second;
    for (int i = lb; i <= rb; i++)
    {
        arr[r][c] = i;
        dfs(arr, seq, cur + 1, n, m, lb, rb);
        arr[r][c] = 0;
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n, m, lb, rb;
    cin >> n >> m >> lb >> rb;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<pii> seq;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            seq.pb({i, j});
    dfs(arr, seq, 0, n, m, lb, rb);
    cout << st.size() << "\n";
    return 0;
}