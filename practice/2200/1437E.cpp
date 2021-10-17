// https://codeforces.com/contest/1437/problem/E
// Make It Increasing

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

const int inf = 2e9 + 5;
int solve()
{
    int n, k, res = 0;
    cin >> n >> k;
    vector<int> arr(n + 2), fix_ids(n + 2), dp(n + 2, -1);
    fix_ids[0] = fix_ids[n + 1] = 1;
    arr[0] = -1e6 - 5;
    arr[n + 1] = 1002000000;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
    {
        int idx;
        cin >> idx;
        fix_ids[idx] = 1;
    }
    for (int i = 2; i <= n; i++)
        if (fix_ids[i - 1] + fix_ids[i] == 2 && arr[i - 1] >= arr[i])
            return -1;
    for (int i = 0; i < n + 1;)
    {
        while (i <= n + 1 && fix_ids[i])
            i++;
        if (i <= n + 1)
        {
            int l = i - 1, r = i;
            while (r <= n + 1 && !fix_ids[r])
                r++;
            int sz = r - l;
            vector<int> small(sz + 1, inf);
            small[0] = 0;
            for (int j = l + 1, rem = arr[l] + 1; j <= r; j++, rem++)
            {
                int cur = arr[j] - rem;
                if (cur >= 0)
                {
                    int low = 0, high = sz - 1, v = 0;
                    while (low <= high)
                    {
                        int mid = low + (high - low) / 2;
                        if (small[mid] <= cur)
                        {
                            v = max(v, mid);
                            low = mid + 1;
                        }
                        else
                            high = mid - 1;
                    }
                    dp[j] = v + 1;
                    small[v + 1] = cur;
                }
            }
            if (dp[r] == -1)
                return -1;
            res += sz - dp[r];
            i = r;
            while (i <= n + 1 && fix_ids[i])
                i++;
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