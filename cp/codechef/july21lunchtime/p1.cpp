#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int LGN = 18;
int solve()
{
    int n, k, res = 1;
    ll s;
    cin >> n >> k >> s;
    vector<ll> arr(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + arr[i];
    vector<vector<int>> nxt(n + 1, vector<int>(LGN));
    for (int i = 0; i < n; i++)
    {
        int low = i + 1, high = n;
        nxt[i][0] = i + 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (pre[mid] - pre[i] <= s)
            {
                nxt[i][0] = max(nxt[i][0], mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    for (int p = 0; p < LGN; p++)
        nxt[n][p] = n;
    for (int p = 1; p < LGN; p++)
        for (int i = 0; i < n; i++)
            nxt[i][p] = nxt[nxt[i][p - 1]][p - 1];
    for (int i = 0; i < n; i++)
    {
        int u = i, tmp = k;
        for (int j = LGN; j >= 0; j--)
        {
            if ((1 << j) <= tmp)
            {
                u = nxt[u][j];
                tmp -= (1 << j);
            }
        }
        res = max(res, u - i);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}