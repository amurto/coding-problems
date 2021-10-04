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

const int N = 1 << 20, LGN = 20;
int arr[N], pos[N][2];
vector<int> st[N][2];
int solve()
{
    int n, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<int> last(LGN), l(n + 1);
    iota(l.begin(), l.end(), 0);
    for (int b = LGN, x = 0; b > 0; b--)
    {
        x |= (1 << b);
        for (int i = 0; i < N; i++)
        {
            st[i][0].clear();
            st[i][1].clear();
        }
        st[0][0].pb(0);
        vector<int> pre(n + 1);
        for (int i = 1, p = 1; i <= n; i++, p ^= 1)
        {
            pre[i] = pre[i - 1] ^ (arr[i] & x);
            st[pre[i]][p].pb(i);
        }
        int bit = b - 1;
        for (int i = 1, p = 1; i <= n; i++, p ^= 1)
        {
            if (!((arr[i] >> bit) & 1))
                last[bit] = i;
            if (last[bit] < l[i])
            {
                l[i] = last[bit];
                int cur = lower_bound(st[pre[i]][p].begin(), st[pre[i]][p].end(), l[i]) - st[pre[i]][p].begin();
                cur = st[pre[i]][p][cur];
                if (cur < i)
                    res = max(res, i - cur);
            }
        }
    }
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