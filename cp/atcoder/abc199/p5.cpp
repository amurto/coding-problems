#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 19;
ll dp[1 << N][N];

int cnt_bit(int mask, int bit)
{
    int cnt = 0;
    for (int b = 0; b <= bit; b++)
        cnt += ((mask >> b) & 1);
    return cnt;
}

ll perm(vector<vector<pii>> &op, int mask, int cur, int n)
{
    if (cur == n)
        return 1ll;
    if (dp[mask][cur] == -1)
    {
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
                continue;
            int nmask = (1 << i) | mask;
            bool valid = true;
            for (int j = 0; valid && j < op[cur].size(); j++)
                if (cnt_bit(nmask, op[cur][j].first) > op[cur][j].second)
                    valid = false;
            if (valid)
                res += perm(op, nmask, cur + 1, n);
        }
        dp[mask][cur] = res;
    }
    return dp[mask][cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y, z;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    vector<vector<pii>> op(n);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        x--;
        y--;
        op[x].pb({y, z});
    }
    cout << perm(op, 0, 0, n) << "\n";
    return 0;
}